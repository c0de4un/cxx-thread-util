# cxx-thread-util
C++ utility library for threads api (posix &amp; Windows).

# Project-Target (why ?)
Writing same patterns of async-works for different small-projects (tutorial games, UI client-server apps)
takes time. Yes, by rewriting old code again you improving skill, learning optimization & errors (bugs).
But having ready-to-use library is also helpful.

# Features
 - handles platform-specific api (Windows & posix) ;
 - errors-handling using events (messages) type ;
 - auto-deletion of forgotten threads (wait until complete or detach) ;
 
 # Requirements
  - C++ 11+
  - MSVC || GCC || Clang
  - CMake
  - Posix or Windows
  
  # Usage
   - Library designed to support STATIC & SHARED (dynamic) linking.
   - due to dynamic nature of allocations using C++, its not required to call
   single-tone specific methods (static functions), like init or terminate, managing-class
   handles factory-calls itself.
