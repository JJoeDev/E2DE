#!/bin/bash

script_dir="$(dirname "$(readlink -f "$0")")"

vendor_path="E2DE/Vendor"
full_vendor_path="$script_dir/$vendor_path"

full_SDL_path="$full_vendor_path/SDL/SDL_CORE"

cd "$full_SDL_path" || {
    echo "-----========== ERROR: Could not change to SDL directory at: $full_SDL_path" >&2 # >&2 redirects the echo to the standard error (stderr)
    exit 1
}

SDL_Build(){
    cmake SDL2 -B build
    make -C build
}

echo "-----========== Would you like to build SDL now? (y/n) ==========-----"
read -r answer

if [ "$answer" = "y" ]; then
    if [ -d "build" ]; then
        SDL_Build
    else
        mkdir "build"
        SDL_Build
    fi

    echo "-----========== SDL has been build to $full_SDL_path/build/ ==========-----"
else
    echo "-----========== Skipping SDL2 build! ==========-----"
fi