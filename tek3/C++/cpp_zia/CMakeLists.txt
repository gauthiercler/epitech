cmake_minimum_required(VERSION 3.9.6)
project(cpp_zia)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Include basic APIeach _ in Array(5)
include_directories(api)
# Include Lille API
include_directories(api/pp)

add_subdirectory(server)
add_subdirectory(lib/rnetwork)
add_subdirectory(lib/nobyte)
add_subdirectory(lib/shared)
add_subdirectory(zia_modules)
add_subdirectory(tests)