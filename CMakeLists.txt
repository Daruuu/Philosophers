cmake_minimum_required(VERSION 3.30)
project(Philosophers C)

set(CMAKE_C_STANDARD 99)

#file(GLOB SRC_DIR philo/src/*.c)

include_directories(philo/includes)

add_executable(Philosophers
        philo/src/main.c
        philo/src/get_time.c
        philo/src/init_structs.c
        philo/src/check_arguments.c
        philo/src/print.c
        philo/src/routine_philos.c
        philo/src/utils.c
)

target_link_libraries(Philosophers pthread )#-g -fsanitize=thread)