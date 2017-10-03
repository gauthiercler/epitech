cmake_minimum_required(VERSION 3.6)
project(PSU_2016_lemipc)
set(CMAKE_C_STANDARD 99)

set(INCLUDES
        includes/lem_ipc.h
        includes/solver.h)

set(ARENA_SOURCES
        sources/arena/is_empty.c
        sources/arena/display.c
        sources/arena/update_arena.c
        sources/arena/get_free_spot.c
        sources/arena/is_winner.c
        sources/arena/is_last_of_team.c
        sources/arena/exit.c)

set(IPC_SOURCES
        sources/ipc/ipc.c
        sources/ipc/init_ipc.c
        sources/ipc/clean_ipc.c)

set(PLAYER_SOURCES
        sources/player/simulation.c
        sources/player/init_player.c
        sources/player/insert_player.c
        sources/player/is_alive.c
        sources/player/move.c
        sources/player/target.c
        sources/player/attack.c

        sources/player/streamer/startup_match.c
        sources/player/streamer/broadcast.c

        sources/player/captain/determine_target.c

        sources/player/channel/emit_order.c
        sources/player/channel/receive_order.c)

set(ASTAR_SOURCES
        sources/path_finding/clean/clean.c
        sources/path_finding/list/get_node.c
        sources/path_finding/list/list.c
        sources/path_finding/misc/xmalloc.c
        sources/path_finding/solve/gen_path.c
        sources/path_finding/solve/get_pos.c
        sources/path_finding/solve/solve.c
        sources/path_finding/solve/verif.c)

set(SOURCES
        sources/main.c
        sources/args_handler/parse_args.c
        sources/errors/error.c
        sources/misc/xrand.c sources/player/captain/command.c sources/player/follow_command.c)

add_executable(PSU_2016_lemipc
        ${INCLUDES}
        ${SOURCES}
        ${ARENA_SOURCES}
        ${IPC_SOURCES}
        ${PLAYER_SOURCES}
        ${ASTAR_SOURCES})

add_definitions(-W -Wall -Wextra)
target_link_libraries(PSU_2016_lemipc -lpthread)


include_directories(
        includes
)

#add_subdirectory(bonus)