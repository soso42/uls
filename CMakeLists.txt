cmake_minimum_required(VERSION 3.16)
project(uls C)

set(CMAKE_C_STANDARD 11)

file(GLOB uls_SRC
        "libmx/inc/*.h"
        "libmx/src/*.c"
        "inc/*.h"
        "src/*.c"
        "src/errors/*.c"
        )

add_executable(uls ${uls_SRC})
