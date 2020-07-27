workspace "Apollo"
  configurations { "Debug", "Release", "Dist" }
  architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Apollo"
  location "Apollo"  
  kind "StaticLib"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin/" .. outputdir .. "/%{prj.name}")

  files {
    "%{prj.name}/src/**.cpp",
    "%{prj.name}/src/**.mm",
    "%{prj.name}/src/**.h",
  }

  includedirs {
    "%{prj.name}/src/Apollo/"
  }
      
  postbuildcommands {
    ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/libApollo.a")
  }

  filter "system:macosx"
    cppdialect "C++17"
    staticruntime "On"

    defines {
      "GL_SILENCE_DEPRECATION",
      "APOLLO_MACOS"
    }

  filter "configurations:Debug"
    defines "APOLLO_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "APOLLO_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "APOLLO_DIST"
    optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
      "%{prj.name}/*.cpp",
      "%{prj.name}/*.h"
    }

    sysincludedirs
    {
      "Apollo/src/"
    }

    includedirs
    {
      "Apollo/src/Apollo/"
    }

    links
    {
      "Apollo",
      "Cocoa.framework",
      "OpenGL.framework"
    }

  filter "system:macosx"
    cppdialect "C++17"
    staticruntime "On"

    defines {
      "GL_SILENCE_DEPRECATION",
      "APOLLO_MACOS"
    }

  filter "configurations:Debug"
    defines "APOLLO_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "APOLLO_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "APOLLO_DIST"
    optimize "On"