#!/bin/bash

script_dir="$(dirname "$(readlink -f "$0")")"

vendor_path="E2DE/Vendor"
full_vendor_path="$script_dir/$vendor_path"

full_SDL_path="$full_vendor_path/SDL/SDL_CORE"
full_BGFX_path="$full_vendor_path/BGFX"

cd "$full_SDL_path" || {
    echo "-----========== ERROR: Could not change to SDL directory at: $full_SDL_path" >&2 # >&2 redirects the echo to the standard error (stderr)
    exit 1
}

if [ -d "build" ]; then
    echo "-----========== Build folder exists, moving on ==========-----"
else    
    echo "-----========== Would you like to build SDL now? (y/n) ==========-----"
    read -r answer

    if [ "$answer" = "y" ]; then
        mkdir "build"
        cmake SDL2 -B build
        make -C build
        echo "-----========== SDL has been build to $full_SDL_path/build/ ==========-----"
    else
        echo "-----========== Skipping SDL2 build! ==========-----"
    fi
fi

cd "$full_BGFX_path" || {
    echo "-----========== ERROR: Could not change to BGFX directory at: $full_BGFX_path" >&2
    exit 1
}

echo "-----========== Would you like to build BGFX now? (It may take a while) (y/n) ==========-----"
read -r answer

if [ "$answer" = "y" ]; then
    make -C bgfx linux-release64
    echo "-----========== BGFX has been build."
    echo "Would you like to run the demo? (y/n) ==========-----"

    read -r answer

    if [ "$answer" = "y" ]; then
        cd "$script_dir" || {
            echo "-----========== ERROR: Could not change to BASE directory at: $script_dir" >&2
            exit 1
        }
        ./testrun-d.sh
    fi
else
    echo "-----========== Everything has been setup and is ready to be used! ==========-----"
fi