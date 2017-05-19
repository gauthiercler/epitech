cmake_minimum_required(VERSION 3.6)
project(PSU_2016_philo)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        includes/philo.h
        includes/extern.h
        sources/main.c
        sources/list/clean_list.c
        sources/list/create_list.c
        sources/error/error.c
        sources/simulation/simulation.c
        sources/simulation/philo_think.c
        sources/simulation/philo_sleep.c
        sources/simulation/philo_eat.c
        sources/simulation/philo_pick.c
        sources/opts/opts.c)

add_executable(philo ${SOURCE_FILES})
add_definitions(-Wall -W -Wextra -L. -lriceferee -lpthread)
target_include_directories(philo PRIVATE includes)