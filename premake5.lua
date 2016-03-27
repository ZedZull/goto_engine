workspace "goto"
    configurations { "Debug", "Release" }
    platforms { "Win32" }
    location "build"

project "goto"
    kind "ConsoleApp"
    language "C"
    targetdir "bin/%{cfg.buildcfg}"

    files { "src/unity_build.c" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    filter "platforms:Win32"
        system "Windows"
        architecture "x32"
        includedirs { "external/win32/SDL2-2.0.4/include" }
        libdirs { "external/win32/SDL2-2.0.4/lib/x86" }
        links { "opengl32", "SDL2" }
        buildoptions { "/MT", "/GR-", "/EHa-" }
