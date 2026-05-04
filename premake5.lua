workspace "Vritra"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Vritra"
    location "Vritra"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "VT_PLATFORM_WINDOWS",
            "VT_BUILD_DLL",
            "_WINDLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        filter "configurations:Debug"
            defines "VT_DEBUG"
            symbols "On"
        filter "configurations:Release"
            defines "VT_RELEASE"
            optimize "On"
        filter "configurations:Dist"
            defines "VT_DIST"
            optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Vritra/vendor/spdlog/include",
        "Vritra/src"
    }

    links
    {
        "Vritra"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "VT_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines "VT_DEBUG"
            symbols "On"
        filter "configurations:Release"
            defines "VT_RELEASE"
            optimize "On"
        filter "configurations:Dist"
            defines "VT_DIST"
            optimize "On"