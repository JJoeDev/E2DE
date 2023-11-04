#!/bin/bash

folders=("bin" "build" "obj")

rm -r "${folders[@]}"

sleep 1

./build-d.sh

cd "$(dirname "$0")/Demo"

rm -r "${folders[@]}"

sleep 1

./build-d.sh