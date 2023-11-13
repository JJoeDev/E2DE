#!/bin/bash

folders=("bin" "build" "obj")

rm -r "${folders[@]}"

./build-d.sh

cd "$(dirname "$0")/Demo"

rm -r "${folders[@]}"

./build-d.sh