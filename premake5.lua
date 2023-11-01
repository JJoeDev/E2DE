workspace "E2DE"
    configurations { "Debug", "Release" }
    architecture "x64"
    location "build"

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
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

    includedirs{
        "E2DE/src",
        os.getenv("SDL2_DIR") and (os.getenv("SDL2_DIR") .. "/include") or "/usr/include/SDL2" -- Only works if ENV PATH is set
    }

    filter "system:windows"
        libdirs{
            os.getenv("SDL2_DIR") and ("%{sdl2_dir}/lib") -- If PATH is not set figure out how to use or to get some other way to go there
        }
    filter "system:linux"
        links{
            "SDL2"
        }