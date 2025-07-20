#!/usr/bin/env bash
export NIXPKGS_ALLOW_UNFREE=1
tmp="/tmp/code-lines-dev"

mkdir $tmp
nix-shell --run "TMPDIR=$tmp code ."
