cmake_minimum_required(VERSION 3.8)
project(gomoku)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        src/Engine.cpp
        src/Engine.hpp
        src/Board.cpp
        src/Board.hpp
        src/Brain.cpp
        src/Brain.hpp
        src/CommandManager.cpp
        src/CommandManager.hpp
        src/Move.hpp
        src/MoveGenerator.cpp
        src/MoveGenerator.hpp
        src/Constants.hpp
        src/BoardEvaluator.cpp
        src/BoardEvaluator.hpp)
add_executable(pbrain-tenderflow ${SOURCE_FILES})

if (MSVC)
    set_target_properties(pbrain-tenderflow PROPERTIES COMPILE_FLAGS "/Ox /Ob2 /Oi /Ot /Oy-")
endif()