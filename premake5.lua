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

function setBxCompact()
    filter { "system:linux" }
        includedirs { path.join(BX_DIR, "include/compact/linux") }
end

project "E2DE"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    exceptionhandling "Off"
    rtti "Off"
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
            path.join(BX_DIR, "include"),
            path.join(BIMG_DIR, "include"),
        }

    filter "system:linux"
        libdirs{
            "E2DE/Vendor/SDL/build",
            "E2DE/Vendor/ECS/build",
            "E2DE/Vendor/BGFX/bgfx/.build/linux64_gcc/bin",
        }

    links{
        "bgfx",
        "bimg",
        "bx",
        "SDL2",
        "SDL2main",
    }

    filter "system:linux"
        links { "dl", "GL", "pthread", "X11" }
    setBxCompact()

project "bgfx"
    kind "StaticLib"
    language "C++"
    cppdialect "C++14"
    exceptionhandling "Off"
    rtti "Off"
    defines "__STDC_FORMAT_MACROS"

    files{
        path.join(BGFX_DIR, "include/bgfx/**.h"),
        path.join(BGFX_DIR, "src/*.cpp"),
        path.join(BGFX_DIR, "src/*.h"),
    }

    excludes{
        path.join(BGFX_DIR, "src/amalgamated.cpp"),
        path.join(BGFX_DIR, "src/dxgi.cpp"),
        path.join(BGFX_DIR, "src/renderer_d3d11.cpp"),
        path.join(BGFX_DIR, "src/renderer_d3d12.cpp"),
    }

    includedirs{
        path.join(BX_DIR, "include"),
        path.join(BIMG_DIR, "include"),
        path.join(BGFX_DIR, "include"),
        path.join(BGFX_DIR, "3rdparty"),
        path.join(BGFX_DIR, "3rdparty/dxsdk/include"),
        path.join(BGFX_DIR, "3rdparty/khronos"),
    }

    setBxCompact()

project "bimg"
    kind "StaticLib"
    language "C++"
    cppdialect "C++14"
    exceptionhandling "Off"
    rtti "Off"

    files{
        path.join(BIMG_DIR, "include/bimg/*.h"),
        path.join(BIMG_DIR, "src/image.cpp"),
        path.join(BIMG_DIR, "src/image_gnf.cpp"),
        path.join(BIMG_DIR, "src/*.h"),
        path.join(BIMG_DIR, "3rdparty/astc-codec/src/decoder/*.cc"),
    }

    includedirs{
        path.join(BX_DIR, "include"),
        path.join(BIMG_DIR, "include"),
        path.join(BIMG_DIR, "3rdparty/astc-codec"),
        path.join(BIMG_DIR, "3rdparty/astc-codec/include"),
    }
    setBxCompact()

project "bx"
    kind "StaticLib"
    language "C++"
    cppdialect "C++14"
    exceptionhandling "Off"
    rtti "Off"
    defines "__STDC_FORMAT_MACROS"

    files{
        path.join(BX_DIR, "include/bx/*.h"),
        path.join(BX_DIR, "include/bx/inline/*.inl"),
        path.join(BX_DIR, "src/*.cpp"),
    }

    excludes{
        path.join(BX_DIR, "src/amalgamated.cpp"),
        path.join(BX_DIR, "src/crtnone.cpp"),
    }

    includedirs{
        path.join(BX_DIR, "3rdparty"),
        path.join(BX_DIR, "include"),
    }
    
    setBxCompact()