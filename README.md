# Mulbery (桑)
## What is Mulberry?
Mulberry is a project that aims to have a matching source decompilation of the PS2 game Kuon. Once we have a matching decompiled rom we want to port the game to modern hardware.


## Progress

![progress](progress.svg)

- **2901/2901 functions matched**, all 215 game units built from C, linked binary checksum matches SLUS_210.07.
- **Not done: 118 functions in 42 source files** still contain inline `__asm__` (directly or via inline VU0 helpers),
  14 of them with raw `.word` instruction bytes. Full list: [NOT_DONE.md](NOT_DONE.md).
  2783/2901 functions (95.9%) are done in clean C.
- `src/unklib_00195CA0.c` and `src/unklib_0019FA70.c` still pull 7 rodata constants via `INCLUDE_RODATA`.
- Sony SDK libraries (`sdk/sce/ee/*`, 189 units) are still linked from asm.

Regenerate the graphic and NOT_DONE.md with `python3 tools/progress_svg.py`.


## Disclaimer
No game assets are hosted on this repository. You must provide them yourself, copying them from a legal copy.


## Getting Started & Building
Linux (x86-64) or macOS (aarch64) are required in order to build this project. You'll also need at least `python 3.8` to run any command. Your operating system should come with `python3` already installed. If not, please follow your distribution's instructions to install it. Python is a mandatory dependency, as many core tools are written in python. On Ubuntu, if necessary, python3 can be installed with the following command:
```bash
sudo apt install python3-full
```

### Install dependencies (Ubuntu)
```bash
sudo apt install make python3-venv
```

### Install decompals binutils

This project requires a custom PS2-specific version of binutils to assemble the extracted MIPS assembly. The system-provided `binutils-mips-linux-gnu` package may not work correctly with PS2 assembly, so manual installation is required.

On Linux, download the [binutils-mips-ps2-decompals-linux-x86-64.tar.gz (v0.10)](https://github.com/decompals/binutils-mips-ps2-decompals/releases/download/v0.10/binutils-mips-ps2-decompals-linux-x86-64.tar.gz) package, or on macOS aarch64 [binutils-mips-ps2-decompals-macos-arm64.tar.gz (v0.10)](https://github.com/decompals/binutils-mips-ps2-decompals/releases/latest/download/binutils-mips-ps2-decompals-macos-arm64.tar.gz).

Extract the archive to a location of your choice, for example:

```bash
sudo mkdir -p /opt/binutils-mips-ps2-decompals
sudo tar -xzf binutils-mips-ps2-decompals-linux-x86-64.tar.gz -C /opt/binutils-mips-ps2-decompals
```

Then add the bin directory to your `PATH` environment variable:

```bash
export PATH="/opt/binutils-mips-ps2-decompals/:$PATH"
```

To make this change persistent, add the line above to your shell configuration file (for example `~/.bashrc`, `~/.zshrc`, or equivalent), then restart your terminal or reload your shell.

Verify the installation by running:

```bash
mips-ps2-decompals-as --version
```

If the installation was successful, the command should print the assembler version information.


### Install the EE-GCC toolchain

The default compiler is MWCC 3.0b52. One unit, `unklib_001720A0`, was originally built with
EE-GCC `2.96-ee-001003-1` (`-O2 -G8 -mno-abicalls -fno-pic`); MWCC does not reproduce it.
`configure.py` selects the compiler per source file.

The [EE-GCC 2.96 archive](https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.96.tar.xz)
contains i386 Linux executables, so it needs an x86 Linux environment with i386 support
(also when developing on macOS). On Ubuntu, install the 32-bit runtime with
`sudo apt install libc6-i386`, then run from the repo root:

```bash
archive=$(mktemp)
curl -fL https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.96.tar.xz -o "$archive"
printf '0590d2ca9da8f5903889d66761220d14b47a8d14ba987ca53db84a1650a1fd0a  %s\n' "$archive" | sha256sum -c -
mkdir -p tools/cc/ee-gcc2.96
tar -xJf "$archive" -C tools/cc/ee-gcc2.96
rm "$archive"
```

Compiler binaries are downloaded, not committed.


### Setup a Virtual Environment for Python
Python's virtual environments are the preferred way to use this software, as you may not be allowed to install packages globally. 
```bash
python3 -m venv .venv
source .venv/bin/activate
python3 -m pip install -r requirements.txt
```

### Copy assets from game DVD/ISO
The main executable is needed in order to perform the decompilation.

#### Use the prototype build, not the retail one
The expected checksum (`config/checksum.sha1`) is against the **prototype** build of Kuon — the *Aug 2, 2004* prototype ("Alpha Preview") disc, whose executable is **unstripped** and still carries its symbol tables (`.symtab`, `.relmain`, `.debug`). The retail USA disc ships a *different*, stripped executable; no amount of matching decompilation will ever make it pass the checksum, so extract `SLUS_210.07` from the prototype disc and put it at `config/SLUS_210.07`.

Both revisions are easy to tell apart by size and by hash:

| `SLUS_210.07` | prototype (required) | retail (won't match) |
| --- | --- | --- |
| file size | 5,678,284 | 1,409,200 |
| file SHA-1 | `7124b436f61ebbe5944e4b50b7d4c04475711c11` | `daaee74780e8294dd27f06c8649a1d08a141734b` |
| `main` section size | 1,407,104 | 1,408,640 |
| `main` section SHA-1 | `294a1d49a96589c9caf68837b8d914b7a1ba2ce1` | `df795794b3309c1a851c310fd8ca1b70af099356` |

The checksum in `config/checksum.sha1` is the SHA-1 of the **flat `main` section** of the *linked* executable (`objcopy -O binary build/SLUS_210.07.elf build/SLUS_210.07`, 1,407,104 bytes) — not of the ELF file itself. That is the last step of `make build`, and it must end with:

```
build/SLUS_210.07: OK
```

To check your copy of the executable before building:

```bash
sha1sum config/SLUS_210.07                                                     # 7124b436... for the prototype
mips-ps2-decompals-objcopy -O binary config/SLUS_210.07 /tmp/main.bin
sha1sum /tmp/main.bin                                                          # 294a1d49...
```

Use the same prototype disc for the rest of the game assets, since data files differ between revisions too.

#### Build Instructions
To do a basic build run
```bash
make clean
make configure
make build
```
In that order to ensure a clean building environment each time

### Command Help
To have a list all available commands, run `make` without targets:
```bash
make
```

## Decompiling a TU
1. Add the decompiled code to the TU's `c` file in `src/`
2. Update `config/kuon.yaml`:
   1. Replace `asm` with `c` for the TU you are decompiling
   2. Add a leading dot (`.`) to the type (e.g., `rodata` -> `.rodata`) of each subsection that belongs to the TU
3. Reconfigure the project
4. Build the project

