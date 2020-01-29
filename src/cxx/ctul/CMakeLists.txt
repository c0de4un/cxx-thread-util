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
set ( PROJECT_NAME "ctul-lib" )

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

set ( CTUL_HEADERS
	# CONFIG
	"cfg/atomic.hpp"
	"cfg/types.hpp"
	"cfg/collections.hpp"
	"cfg/memory.hpp"
	"cfg/mutex.hpp"
	"cfg/thread.hpp"
	# UTILS
	"core/utils/IMutex.hxx"
	"core/utils/SMutex.hpp"
	# CORE
	"core/ThreadBase.hpp"
	"core/events/IThreadEvent.hxx"
	"core/events/ThreadErrorEvent.hpp"
	"core/IThreadGroup.hxx"
	"core/ThreadGroup.hpp"
	"core/ThreadPool.hpp"
	"core/IThread.hxx"
	"core/ctul.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set ( CTUL_SOURCES
	# UTILS
	"core/utils/SMutex.cpp"
	# CORE
	"core/events/ThreadErrorEvent.cpp"
	"core/ThreadBase.cpp"
	"core/ThreadGroup.cpp"
	"core/ThreadPool.cpp"
	"core/ctul.cpp" )

# =================================================================================
# MODULES
# =================================================================================

# Platform
if ( LINUX OR APPLE )
	include ( "posix/posix.cmake" )
elseif ( WIN32 OR WIN64 OR MINGW )
	include ( "windows/windows.cmake" )
endif ( LINUX )

# =================================================================================
# BUILD
# =================================================================================

# SHARED Library
if ( CXX_THREADS_LIB_BUILD_SHARED )
	# Export all Symbols by default (on Windows creates '.lib'+ '.dll').
	set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

	# Add SHARED Library Object
	add_library ( ctul SHARED ${CTUL_HEADERS} ${CTUL_SOURCES} )

	# Configure SHARED Library Object
	set_target_properties ( ctul PROPERTIES
		PUBLIC_HEADER ${CTUL_HEADERS}
		RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR}
		VERSION ${PROJECT_VERSION} )

	# INFO
	message ( STATUS "${PROJECT_NAME} - SHARED Library Build complete. Use <ctul> for linking." )
else ( CXX_THREADS_LIB_BUILD_SHARED ) # STATIC Library

	add_library ( ctul STATIC ${CTUL_HEADERS} ${CTUL_SOURCES} )

	# Configure SHARED Library Object
	set_target_properties ( ctul PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR}
		VERSION ${PROJECT_VERSION} )

	# INFO
	message ( STATUS "${PROJECT_NAME} - STATIC Library Build complete. Use <ctul> for linking." )
endif ( CXX_THREADS_LIB_BUILD_SHARED )

# =================================================================================
# INSTALL
# =================================================================================

if ( CXX_THREADS_LIB_BUILD_SHARED )
	# Import GNU Install Rules
	include( GNUInstallDirs )

	# Files to Install
	install( TARGETS ctul
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} )
endif ( CXX_THREADS_LIB_BUILD_SHARED )