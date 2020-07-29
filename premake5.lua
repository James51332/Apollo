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
    "%{prj.name}/vendor/glm/**.hpp",
    "%{prj.name}/vendor/glm/**.inl"
  }

  includedirs {
    "%{prj.name}/src/Apollo"
  }

  sysincludedirs
  {
    "%{prj.name}/vendor/glm"
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
      "%{prj.name}/*.h",
    }

    includedirs
    {
      "Apollo/src/Apollo"
    }

    sysincludedirs
    {
      "Apollo/src",
      "Apollo/vendor/glm"
    }

    links
    {
      "Apollo",
      "Cocoa.framework",
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