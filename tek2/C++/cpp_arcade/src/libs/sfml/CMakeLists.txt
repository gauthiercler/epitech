set(CMAKE_CXX_STANDARD 11)
project(cpp_arcade)

set(HEADER_FILES
        includes/Sfml.hpp includes/SfmlFrame.hpp includes/SfmlPicture.hpp includes/SfmlSprite.hpp includes/SfmlEvent.hpp)

set(SOURCE_FILES
        sources/Sfml.cpp
        sources/SfmlFrame.cpp
        sources/SfmlPicture.cpp
        sources/SfmlSprite.cpp
        sources/SfmlEvent.cpp
        ../common/Utils.cpp includes/SfmlSound.hpp sources/SfmlSound.cpp)

add_executable(arcade_sfml ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(arcade_sfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio)
add_definitions(-W -Wall -Wextra)

include_directories(
        ../../interfaces
        ../../errors
        ../common
        includes
)