cmake_minimum_required(VERSION 3.5.1)
project(enemy)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/)

include_directories(.)
set(COMMON ../shared/ECS/include/ISpawner.hpp Config.hpp)

# Creation of shared library little_enemy (First mob)
set(LITTLE_ENEMY_SOURCES little_enemy/LittleEnemy.cpp little_enemy/LittleEnemy.hpp)
add_definitions(-DENEMY_EXPORTS)
add_library(little_enemy SHARED ${LITTLE_ENEMY_SOURCES} ${COMMON})

if (WIN32)
    set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
    find_package(SFML 2 REQUIRED audio graphics window system)
    if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(little_enemy ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    endif()
    target_link_libraries(little_enemy rtecs)
endif()