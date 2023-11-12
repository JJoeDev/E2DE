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

    filter "system:linux" -- ADD WINDOWS SUPPORT LATER
        includedirs{
            "E2DE/src",        
            "E2DE/Vendor/SDL/build/include/SDL2",
            "E2DE/Vendor/ECS/EnTT/src/entt",
        }

    filter "system:linux"
        libdirs{
            "E2DE/Vendor/SDL/build",
            "E2DE/Vendor/ECS/build",
        }

    filter "system:linux"
        links{
            "SDL2",
            "SDL2main",
        }