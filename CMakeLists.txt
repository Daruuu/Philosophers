cmake_minimum_required(VERSION 3.30)
project(Philosophers C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRC_DIR philo/src/*.c)

include_directories(philo/includes)

add_executable(Philosophers
        ${SRC_DIR}
        philo/src/get_time.c
        philo/src/check_arguments.c
        philo/src/print.c
)

target_compile_options(Philosophers PRIVATE -pthread)
target_link_libraries(Philosophers pthread)