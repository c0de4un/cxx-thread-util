# // ------------------------------------------------------------------------------
#
# This is simple ctul-lib executable demo.
#
# License: see "LICENSE" file.
# Tools: Visual Studio Community, Ninja, CMake, MSVC || CLang || GCC.
# API: C/C++.
# Platforms: Any with C++.
# 
# // ------------------------------------------------------------------------------

# =================================================================================
# CMake Meta-Data
# =================================================================================

# CMake-Version
cmake_minimum_required ( VERSION 3.6 FATAL_ERROR )

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "ctul-demo" )

# Project Version
set ( PROJECT_VERSION 1.0.0 )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION "ctul - CXX Threading Utility Library" LANGUAGES C CXX )

# C Version
#set ( CMAKE_C_STANDARD 99 )

# C++ Version
#set ( CMAKE_CXX_STANDARD 11 )

# Make Build Libs & Executables to be position-independent, like SHARED libs.
#set ( CMAKE_POSITION_INDEPENDENT_CODE ON )

# =================================================================================
# CONFIGS
# =================================================================================

# =================================================================================
# HEADERS
# =================================================================================

set ( DEMO_HEADERS
	"MyThread.hpp"
	"main.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set ( DEMO_SOURCES
	"MyThread.cpp"
	"main.cpp" )

# =================================================================================
# BUILD
# =================================================================================

# Add Executable-Object
add_executable (  ctul_demo ${DEMO_HEADERS} ${DEMO_SOURCES} )

# Include Libraries Headers for Executable-Object
target_include_directories ( ctul PUBLIC "../ctul" )

# Configure Executable-Object
set_target_properties ( ctul_demo PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR}
	VERSION ${PROJECT_VERSION} )

# Link Executable-Object
target_link_libraries ( ctul_demo ctul )