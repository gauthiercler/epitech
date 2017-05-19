cmake_minimum_required(VERSION 3.3)
project(gfx_scroller)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    srcs/main.c include/megalovania.h srcs/loop/loop.c srcs/loop/initialization.c srcs/event/keys.c srcs/misc/fill.c srcs/misc/pixel.c srcs/misc/line.c srcs/misc/tektext.c srcs/stars/draw_star.c srcs/misc/draw_square.c srcs/stars/gen_stars.c srcs/front/front_draw.c srcs/sprite/draw_sprite.c srcs/morph.c srcs/sprite/peanut.c)

add_executable(gfx_scroller ${SOURCE_FILES})
target_include_directories(gfx_scroller PRIVATE include)
target_include_directories(gfx_scroller PRIVATE /home/keyrise/.froot/include)