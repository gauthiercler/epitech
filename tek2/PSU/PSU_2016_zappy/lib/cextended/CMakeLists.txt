cmake_minimum_required(VERSION 3.7)
project(C_Extended)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Wextra -O2")

set(SOURCE_FILES
        includes/array_extended.h
        includes/circular_buffer.h
        includes/string_extended.h
        srcs/array_extended/count.c
        srcs/circular_buffer/clear.c
        srcs/circular_buffer/destroy.c
        srcs/circular_buffer/get_pos.c
        srcs/circular_buffer/get_remaining_read.c
        srcs/circular_buffer/get_remaining_space.c
        srcs/circular_buffer/get_size.c
        srcs/circular_buffer/is_full.c
        srcs/circular_buffer/new.c
        srcs/circular_buffer/read.c
        srcs/circular_buffer/skip.c
        srcs/circular_buffer/write.c
        srcs/string_extended/explode.c
        srcs/string_extended/nb_token_ahead.c
        srcs/string_extended/strip_extra_token.c
        srcs/string_extended/strpos.c
        includes/list.h
        srcs/list/new.c
        srcs/list/destroy.c
        srcs/list/size.c
        srcs/list/at.c
        srcs/list/front.c
        srcs/list/back.c
        srcs/list/push_at.c
        srcs/list/push_front.c
        srcs/list/push_back.c
        srcs/list/pop_at.c
        srcs/list/pop_front.c
        srcs/list/pop_back.c
        srcs/list/pop_data.c
        srcs/list/dump.c srcs/list/search.c srcs/list/foreach.c srcs/circular_buffer/size_before.c srcs/string_extended/free_explode.c)

add_library(cextended STATIC ${SOURCE_FILES})
target_include_directories(cextended PRIVATE includes)