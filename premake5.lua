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
        "E2DE/Vendor/SDL2/include/**.h",
        "E2DE/Vendor/SDL2/src/*.h",
        "E2DE/Vendor/SDL2/src/*.c",
        "E2DE/Vendor/SDL2/src/core/*.c",
    }

    filter "system:windows"
        files{
            "E2DE/Vendor/SDL2/src/core/windows/*.h",
            "E2DE/Vendor/SDL2/src/core/windows/*.c",
            "E2DE/Vendor/SDL2/src/core/windows/*.cpp",
            "E2DE/Vendor/SDL2/src/hidapi/windows/hid.c",
        }
    filter "system:linux"
        files{
            "E2DE/Vendor/SDL2/src/core/linux/*.h",
            "E2DE/Vendor/SDL2/src/core/linux/*.c",
            "E2DE/Vendor/SDL2/src/hidapi/linux/hid.c",
            "E2DE/Vendor/SDL2/src/hidapi/linux/hidraw.cpp"
        }

    includedirs{
        "E2DE/src",
        "E2DE/Vendor/SDL2/include"
    }