#!/bin/bash

premake5 gmake2

make -C build/ config=release

./bin/Release/E2DE