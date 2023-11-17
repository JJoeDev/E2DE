local BGFX_DIR  = "E2DE/Vendor/BGFX/bgfx"
local BIMG_DIR  = "E2DE/Vendor/BGFX/bimg"
local BX_DIR    = "E2DE/Vendor/BGFX/bx"
local SDL_DIR   = "E2DE/Vendor/SDL/SDL_CORE/"
local ENTT_DIR  = "E2DE/Vendor/ECS/EnTT"

workspace "E2DE"
    configurations { "Debug", "Release" }
    architecture "x64"
    location "build"

    filter "configurations:Debug"
        defines { 
            "DEBUG",
            "BX_CONFIG_DEBUG=1"
        }
        optimize "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { 
            "NDEBUG",
            "BX_CONFIG_DEBUG=0",
        }
        optimize "On"

project "E2DE"
    kind "StaticLib"
    language "C++"
    targetdir ("bin/%{cfg.buildcfg}")
    objdir ("obj/%{cfg.buildcfg}")

    files{
        "E2DE/src/**.cpp",
        "E2DE/src/**.h",
    }

    filter "system:linux" -- ADD WINDOWS SUPPORT LATER
        includedirs{
            "E2DE/src",        
            path.join(SDL_DIR, "build/include/SDL2"),
            path.join(ENTT_DIR, "src/entt"),
            path.join(BGFX_DIR, "include"),
            --path.join(BX_DIR, "include"),
            --path.join(BIMG_DIR, "include"),
        }

    filter "system:linux"
        libdirs{
            "E2DE/Vendor/SDL/build",
            "E2DE/Vendor/ECS/build",
            "E2DE/Vendor/BGFX/bgfx/.build/linux64_gcc/bin",
        }

    filter "system:linux"
        links { "GL", "pthread", "X11", "rt" }

    links{
        "bgfxRelease",
        --"bimg",
        --"bx",
        "SDL2",
        "SDL2main",
    }
