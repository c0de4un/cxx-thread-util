# // ------------------------------------------------------------------------------
#
# This CMake-file contains settings (options) for project.
# 
# // ------------------------------------------------------------------------------

# Build Demo-Executable ?
option ( CXX_THREADS_LIB_BUILD_DEMO "Build executable demo-app ?" ON )

# Build SHARED Library
option ( CXX_THREADS_LIB_BUILD_SHARED "Build SHARED (DYNAMIC) library ? If not, STATIC library build used." OFF )