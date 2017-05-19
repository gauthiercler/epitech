cmake_minimum_required(VERSION 3.6)
project(cpp_nanotekspice)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(CORE
        sources/interfaces/IParser.cpp sources/interfaces/IParser.hpp
        sources/classes/parser/Parser.cpp sources/classes/parser/Parser.hpp
        sources/interfaces/IComponent.cpp sources/interfaces/IComponent.hpp
        sources/classes/AComponent.cpp sources/classes/AComponent.hpp
        sources/classes/Pin.cpp sources/classes/Pin.hpp
        sources/classes/misc/Misc.cpp sources/classes/misc/Misc.hpp
        sources/classes/errors/Error.hpp
        sources/classes/core/Core.cpp
        sources/classes/core/Core.hpp
        sources/main.cpp)

set(COMPONENTS
        sources/classes/components/C4001.cpp sources/classes/components/C4001.hpp
        sources/classes/components/C4008.cpp sources/classes/components/C4008.hpp
        sources/classes/components/C4011.cpp sources/classes/components/C4011.hpp
        sources/classes/components/C4013.cpp sources/classes/components/C4013.hpp
        sources/classes/components/C4017.cpp sources/classes/components/C4017.hpp
        sources/classes/components/C4030.cpp sources/classes/components/C4030.hpp
        sources/classes/components/C4040.cpp sources/classes/components/C4040.hpp
        sources/classes/components/C4069.cpp sources/classes/components/C4069.hpp
        sources/classes/components/C4071.cpp sources/classes/components/C4071.hpp
        sources/classes/components/C4081.cpp sources/classes/components/C4081.hpp
        sources/classes/components/C4094.cpp sources/classes/components/C4094.hpp
        sources/classes/components/C4514.cpp sources/classes/components/C4514.hpp
        sources/classes/components/C4801.cpp sources/classes/components/C4801.hpp
        sources/classes/components/C2716.cpp sources/classes/components/C2716.hpp

        sources/classes/components/True.cpp sources/classes/components/True.hpp
        sources/classes/components/False.cpp sources/classes/components/False.hpp
        sources/classes/components/INPUT.cpp sources/classes/components/INPUT.hpp
        sources/classes/components/OUTPUT.cpp sources/classes/components/OUTPUT.hpp
        sources/classes/components/CLOCK.cpp sources/classes/components/CLOCK.hpp
        sources/classes/components/FULL_ADDER.cpp sources/classes/components/FULL_ADDER.hpp)

set(COMPONENTS-GATES
        sources/classes/components/gates/AND.cpp sources/classes/components/gates/AND.hpp
        sources/classes/components/gates/NAND.cpp sources/classes/components/gates/NAND.hpp
        sources/classes/components/gates/OR.cpp sources/classes/components/gates/OR.hpp
        sources/classes/components/gates/NOR.cpp sources/classes/components/gates/NOR.hpp
        sources/classes/components/gates/XOR.cpp sources/classes/components/gates/XOR.hpp
        sources/classes/components/gates/NOT.cpp sources/classes/components/gates/NOT.hpp
        sources/classes/components/gates/FLIP_FLOP.cpp sources/classes/components/gates/FLIP_FLOP.hpp)

add_executable(cpp_nanotekspice ${CORE} ${COMPONENTS} ${COMPONENTS-GATES})

include_directories(
        .
        sources
        sources/interfaces
        sources/classes
        sources/classes/misc
        sources/classes/components
        sources/classes/components/gates
        sources/classes/errors
        sources/classes/parser)

add_subdirectory(Tests)

add_definitions(-W -Wall -Wextra -Werror)
