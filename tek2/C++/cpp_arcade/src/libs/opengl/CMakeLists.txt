set(CMAKE_CXX_STANDARD 11)

set(HEADER_FILES
        includes/OpenGLGraphic.hpp
        includes/OpenGLFrame.hpp
        includes/OpenGLPicture.hpp
        includes/OpenGLEvent.hpp
        includes/OpenGLSound.hpp
        includes/OpenGLSprite.hpp)

set(SOURCE_FILES
        sources/OpenGLGraphic.cpp
        sources/OpenGLFrame.cpp
        sources/OpenGLPicture.cpp
        sources/OpenGLEvent.cpp
        sources/OpenGLSound.cpp
        sources/OpenGLSprite.cpp
        ../common/Utils.cpp)

add_executable(arcade_opengl ${HEADER_FILES} ${SOURCE_FILES})
add_definitions(-W -Wall -Wextra)
target_link_libraries(arcade_opengl -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lGL -lGLU)

include_directories(
        ../../interfaces
        ../../errors
        ../common
        includes
)