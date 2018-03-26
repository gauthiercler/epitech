cmake_minimum_required(VERSION 3.9)
project(cpp_rtype)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

if(UNIX)
    set (LOADER ../impl/unixDllLoader.cpp)
    set (FILESYSTEM ../FileSystem.hpp ../impl/unixFileSystem.cpp)
endif()

if(WIN32)
    set (LOADER ../impl/win32DllLoader.cpp)
    set (FILESYSTEM ../FileSystem.hpp ../impl/win32FileSystem.cpp)
endif()

add_definitions(-DLIB_EXPORTS)
add_library(test1 SHARED lib1.c)
add_definitions(-DLIB_EXPORTS)
add_library(test2 SHARED lib2.c)
add_executable(libloadertest main.cpp ${LOADER} ${FILESYSTEM})
if (UNIX)
    target_link_libraries(libloadertest dl)
endif()
add_executable(filesystemtest fstest.cpp ${FILESYSTEM})