find_package(Curses REQUIRED)
set(CMAKE_CXX_STANDARD 11)

set(HEADER_FILES
        includes/NCurses.hpp
        includes/Terminal.hpp
#        includes/Window.hpp
        includes/EventHandler.hpp
        includes/Event.hpp)

set(SOURCE_FILES
        sources/NCurses.cpp
        sources/Terminal.cpp
        sources/Window.cpp includes/ColorHandler.hpp sources/ColorHandler.cpp sources/EventHandler.cpp sources/Event.cpp includes/CursesPicture.hpp sources/CursesPicture.cpp includes/CursesSprite.hpp sources/CursesSprite.cpp)

add_executable(arcade_ncurses ${HEADER_FILES} ${SOURCE_FILES})
add_definitions(-W -Wall -Wextra)

include_directories(
        ${CURSES_INCLUDE_DIRS}
        ../../interfaces
        ../../errors
        includes
)

target_link_libraries(arcade_ncurses ${CURSES_LIBRARIES})