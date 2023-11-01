workspace "Demo"
    configurations { "Debug", "Release" }
    architecture "x64"
    location "build"

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

project "Demo"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/%{cfg.buildcfg}")
    objdir ("obj/%{cfg.buildcfg}")

    files{
        "src/**.cpp",
        "src/**.h"
    }

    includedirs {
        "src/",
        "../E2DE/src"
    }

    links {
        "E2DE"
    }

    libdirs {
        "../bin/Debug"
    }