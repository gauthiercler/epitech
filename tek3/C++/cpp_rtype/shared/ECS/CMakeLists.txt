cmake_minimum_required(VERSION 3.5.1)
project(cpp_rtype)

set(CMAKE_CXX_STANDARD 14)

set(RTECS_HEADERS
        include/component/ComponentStore.hpp
        include/component/ComponentType.hpp
        include/system/System.hpp
        include/Entity.hpp
        include/Manager.hpp
        include/util/traits.hpp
        include/component/IdGenerator.hpp
        include/component/types/ComponentIdGenerator.hpp)

set(RTECS_SOURCES
        src/Manager.cpp
        src/IdGenerator.cpp include/component/types/ComponentIdGenerator.hpp include/ISpawner.hpp)

add_definitions(-DRTECS_EXPORTS)
add_library(rtecs SHARED ${RTECS_SOURCES} ${RTECS_HEADERS})
target_include_directories(rtecs PUBLIC include)

if (WIN32)
    set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
    find_package(SFML 2 REQUIRED audio graphics window system)
    if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(rtecs ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    endif()
endif()
