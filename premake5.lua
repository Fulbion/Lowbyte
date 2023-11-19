workspace "Lowbyte"
    architecture "x64"

    configurations
    {
        "Debug",
        "RelWithDebInfo",
        "Release"
    }

outputdir = "%{cfg.buildcfg}"

includeDir = {}
includeDir["GLFW"] = "external/GLFW/include"

include "external/GLFW"

project "Lowbyte"
    location "./"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    pchheader "Lowbyte/pch.hpp"
    pchsource "src/Lowbyte/pch.cpp"

    files
    {
        "include/**.hpp",
        "src/Lowbyte/**.cpp"
    }

    includedirs
    {
        "external/spdlog/include",
        "include",
        "%{includeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LB_PLATFORM_WINDOWS",
            "LB_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "LB_DEBUG"
        symbols "On"

    filter "configurations:RelWithDebInfo"
        defines "LB_RELWITHDEBINFO"
        symbols "On"
        optimize "On"

    filter "configurations:Release"
        defines "LB_RELEASE"
        optimize "On"

project "Sandbox"
    location "example/Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "example/%{prj.name}/include/**.hpp",
        "example/%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "external/spdlog/include",
        "include"
    }

    links
    {
        "Lowbyte"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LB_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "LB_DEBUG"
        symbols "On"

    filter "configurations:RelWithDebInfo"
        defines "LB_RELWITHDEBINFO"
        symbols "On"
        optimize "On"

    filter "configurations:Release"
        defines "LB_RELEASE"
        optimize "On"