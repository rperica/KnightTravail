workspace "KnightTravail"
    architecture "x64"
    
    configurations { "Debug",  "Release"}
    outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "KnightTravail"
    location "KnightTravail"
    kind "ConsoleApp"
    language "c++"

    targetdir("bin/bin/" ..outputdir.."/%{prj.name}")
    objdir("bin/intermediates/" ..outputdir.."/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",      
    }

    includedirs
    {
        "%{prj.name}/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "on"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "on"
            