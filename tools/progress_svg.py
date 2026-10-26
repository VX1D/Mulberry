#!/usr/bin/env python3
"""Render progress.svg (matched functions + per-unit treemap of clean C vs inline asm) and NOT_DONE.md."""
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
W, H_HEAD, H_MAP = 1000, 150, 520
GREEN, AMBER, BG, FG, MUTED = "#3fb950", "#d29922", "#0d1117", "#e6edf3", "#8b949e"


asm_bodies: dict[tuple[str, str], str] = {}


def asm_functions(src: Path) -> dict[str, set[str]]:
    """unit name -> top-level functions that contain __asm__/asm, directly or via an inline helper defined in the same file."""
    out: dict[str, set[str]] = {}
    for p in src.rglob("*.c"):
        t = p.read_text(errors="replace")
        t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
        t = re.sub(r"//[^\n]*", "", t)
        t = re.sub(r"^[ \t]*#(?:[^\n]*\\\n)*[^\n]*", "", t, flags=re.M)
        # keep a marker for raw instruction bytes, drop everything else inside strings
        t = re.sub(r'"(?:\\.|[^"\\\n])*"', lambda m: '"WORD"' if ".word" in m.group() else '""', t)
        t = re.sub(r"'(?:\\.|[^'\\\n])*'", "''", t)
        bodies: dict[str, str] = {}
        inline: set[str] = set()
        depth, start, name = 0, 0, None
        for m in re.finditer(r"[{}]", t):
            if m.group() == "{":
                if depth == 0:
                    mm = re.search(r"(\w+)\s*\([^;{}]*\)\s*$", t[max(0, m.start() - 300):m.start()])
                    name, start = (mm.group(1) if mm else None), m.start()
                    line = t[t.rfind(";", 0, m.start()) + 1:m.start()]
                    if name and re.search(r"\binline\b", line.rsplit("}", 1)[-1]):
                        inline.add(name)
                depth += 1
            else:
                depth -= 1
                if depth == 0 and name:
                    bodies[name] = t[start:m.end()]
        tainted = {n for n, b in bodies.items() if re.search(r"\b(__asm__|asm)\b", b)}
        while True:
            more = {n for n, b in bodies.items() if n not in tainted
                    and any(re.search(rf"\b{h}\s*\(", b) for h in tainted & inline)}
            if not more:
                break
            tainted |= more
        unit = str(p.relative_to(src).with_suffix(""))
        for n in tainted:
            asm_bodies[(unit, n)] = bodies[n] + "".join(bodies[h] for h in tainted & inline if h != n)
        if tainted:
            out[str(p.relative_to(src).with_suffix(""))] = tainted
    return out


def squarify(items, x, y, w, h):
    """items: [(value, payload)] sorted desc; yields (x, y, w, h, payload)."""
    items = [i for i in items if i[0] > 0]
    total = sum(v for v, _ in items)
    if not items:
        return
    scale = w * h / total
    items = [(v * scale, p) for v, p in items]
    while items:
        side = min(w, h)
        row, best = [], float("inf")
        for it in items:
            cand = row + [it]
            s = sum(v for v, _ in cand)
            worst = max(max(side * side * v / (s * s), s * s / (side * side * v)) for v, _ in cand)
            if worst > best:
                break
            row, best = cand, worst
        items = items[len(row):]
        s = sum(v for v, _ in row)
        thick = s / side
        off = 0.0
        for v, p in row:
            length = v / thick
            if w >= h:
                yield x, y + off, thick, length, p
            else:
                yield x + off, y, length, thick, p
            off += length
        if w >= h:
            x, w = x + thick, w - thick
        else:
            y, h = y + thick, h - thick


def main():
    report = json.loads((ROOT / "config/report.json").read_text())
    asm = asm_functions(ROOT / "src")
    m = report["measures"]
    total_fn, matched_fn = m["total_functions"], m["matched_functions"]
    known = {(u["name"], f["name"]) for u in report["units"] for f in u.get("functions", [])}
    asm_fn = sum((unit, fn) in known for unit, fns in asm.items() for fn in fns)
    asm_files = len(asm)
    clean_fn = matched_fn - asm_fn

    units = []
    for u in report["units"]:
        fns = u.get("functions", [])
        code = sum(int(f["size"]) for f in fns)
        bad = sum(int(f["size"]) for f in fns if f["name"] in asm.get(u["name"], ()))
        units.append((code, (u["name"], code, bad)))
    units.sort(key=lambda t: -t[0])
    total_code = sum(c for c, _ in units)
    asm_code = sum(p[2] for _, p in units)

    s = [f'<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="{H_HEAD + H_MAP + 40}" '
         f'font-family="ui-sans-serif,system-ui,Segoe UI,Helvetica,Arial" font-size="13">',
         f'<rect width="100%" height="100%" fill="{BG}"/>',
         f'<text x="20" y="32" fill="{FG}" font-size="20" font-weight="600">Kuon (SLUS_210.07) decompilation</text>']

    def bar(y, label, done, total, color, part=None):
        frac = done / total
        s.append(f'<text x="20" y="{y - 6}" fill="{FG}">{label}</text>')
        s.append(f'<text x="{W - 20}" y="{y - 6}" fill="{FG}" text-anchor="end">'
                 f'{done}/{total} ({frac * 100:.1f}%)</text>')
        s.append(f'<rect x="20" y="{y}" width="{W - 40}" height="14" rx="3" fill="#21262d"/>')
        s.append(f'<rect x="20" y="{y}" width="{(W - 40) * frac:.1f}" height="14" rx="3" fill="{color}"/>')
        if part:
            pw = (W - 40) * part / total
            s.append(f'<rect x="{20 + (W - 40) * frac:.1f}" y="{y}" width="{pw:.1f}" height="14" fill="{AMBER}"/>')

    bar(64, "Functions matched (checksum MATCH)", matched_fn, total_fn, GREEN)
    bar(106, f"Functions in clean C — {asm_fn} still use inline asm ({asm_files} files)",
        clean_fn, total_fn, GREEN, asm_fn)

    y0 = H_HEAD
    s.append(f'<text x="20" y="{y0 - 12}" fill="{MUTED}">Units by code size — '
             f'<tspan fill="{GREEN}">■</tspan> clean C  <tspan fill="{AMBER}">■</tspan> functions with inline asm '
             f'({asm_code}/{total_code} bytes, {asm_code / total_code * 100:.1f}%)</text>')
    for x, y, w, h, (name, code, bad) in squarify(units, 20, y0, W - 40, H_MAP):
        s.append(f'<g><title>{name}: {code} B code, {bad} B in inline-asm functions</title>')
        s.append(f'<rect x="{x:.1f}" y="{y:.1f}" width="{w:.1f}" height="{h:.1f}" fill="{GREEN}" '
                 f'stroke="{BG}" stroke-width="1"/>')
        if bad:
            bh = h * bad / code
            s.append(f'<rect x="{x:.1f}" y="{y + h - bh:.1f}" width="{w:.1f}" height="{bh:.1f}" fill="{AMBER}" '
                     f'stroke="{BG}" stroke-width="1"/>')
        short = name.rsplit("/", 1)[-1]
        if w > 7 * len(short) + 8 and h > 18:
            s.append(f'<text x="{x + 4:.1f}" y="{y + 14:.1f}" fill="{BG}" font-size="11">{short}</text>')
        s.append("</g>")
    s.append(f'<text x="20" y="{H_HEAD + H_MAP + 26}" fill="{MUTED}" font-size="11">'
             f'Generated by tools/progress_svg.py from config/report.json and src/</text>')
    s.append("</svg>")
    rows = sorted((unit, fn) for unit, fns in asm.items() for fn in fns if (unit, fn) in known)
    lines = ["# Not done: functions still using inline asm", "",
             f"{asm_fn} functions in {asm_files} files match the original but still contain inline `__asm__`",
             "(directly or via inline VU0 helpers). They count as matched, not as done.",
             "`.word` = raw instruction bytes in the asm."]
    for unit, fn in rows:
        if f"## src/{unit}.c" not in lines:
            lines += ["", f"## src/{unit}.c", ""]
        word = '"WORD"' in asm_bodies[(unit, fn)]
        lines.append(f"- [ ] `{fn}`" + (" — `.word`" if word else ""))
    (ROOT / "NOT_DONE.md").write_text("\n".join(lines) + "\n")

    out = ROOT / "progress.svg"
    out.write_text("\n".join(s) + "\n")
    print(f"{out}: matched {matched_fn}/{total_fn}, clean C {clean_fn}, asm fns {asm_fn} in {asm_files} files",
          file=sys.stderr)


if __name__ == "__main__":
    main()
