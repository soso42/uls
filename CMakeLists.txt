cmake_minimum_required(VERSION 3.17)
project(uls C)

set(CMAKE_C_STANDARD 11)

file(GLOB uls_SRC
        "libmx/inc/*.h"
        "libmx/src/*.c"
        "inc/*.h"
        "src/*.c"
        )

add_executable(uls ${uls_SRC})
