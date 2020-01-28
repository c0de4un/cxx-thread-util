# // ------------------------------------------------------------------------------
#
# This is simple utility-lib for threading.
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
set ( PROJECT_NAME "cxx-threads-utils-lib" )

# Project Version
set ( PROJECT_VERSION 1.0.0 )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION "Console-helper utility lib demo." LANGUAGES C CXX )

# C Version
#set ( CMAKE_C_STANDARD 99 )

# C++ Version
#set ( CMAKE_CXX_STANDARD 11 )

# Make Build Libs & Executables to be position-independent, like SHARED libs.
#set ( CMAKE_POSITION_INDEPENDENT_CODE ON )

# =================================================================================
# CONFIGS
# =================================================================================

# CMake include-files dir (Global variable for all sub-projects).
set ( PROJECT_CMAKE_INCLUDES_DIR "${CMAKE_SOURCE_DIR}/cmake" )

# Platform-specific
include ( "${PROJECT_CMAKE_INCLUDES_DIR}/platform.cmake" )

# Paths
include ( "${PROJECT_CMAKE_INCLUDES_DIR}/paths.cmake" )

# Options
include ( "${PROJECT_CMAKE_INCLUDES_DIR}/options.cmake" )

# =================================================================================
# MODULES
# =================================================================================

# Library

# Demo