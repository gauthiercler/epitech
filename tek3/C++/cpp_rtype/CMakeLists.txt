cmake_minimum_required(VERSION 3.5.1)
project(cpp_rtype)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include_directories(shared/ECS/include
        shared/rnetwork_extended
        shared/components
        shared/rnetwork
        shared/util
        .)

add_subdirectory(shared/rnetwork)
add_subdirectory(shared/rnetwork_extended)
add_subdirectory(client/)
add_subdirectory(server/)
add_subdirectory(shared/ECS)
add_subdirectory(enemy)


#add_executable(cpp_rtype main.cpp
#shared/components/Star.hpp
#shared/util/util.hpp
#shared/components/ServerID.hpp shared/components/Weapon.hpp)

#add_subdirectory(server/include/libloader/test)

#target_link_libraries(cpp_rtype rnetwork)