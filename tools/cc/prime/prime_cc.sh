#!/bin/bash
# prime_cc.sh PRIMER OUT COMPILER-COMMAND... INPUT.c
# Compiles PRIMER and INPUT in ONE compiler process (primer first) and keeps only INPUT's object as OUT.
set -e
primer=$1; out=$2; shift 2
args=("$@"); n=${#args[@]}
input=${args[n-1]}
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT
"${args[@]:0:n-1}" "$primer" "$input" -o "$tmp"/
cp "$tmp/$(basename "$input" .c).o" "$out"
