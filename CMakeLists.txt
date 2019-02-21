cmake_minimum_required(VERSION 2.8)
project(test)
aux_source_directory(. DIR_SRCS)

add_executable(test ${DIR_SRCS})

add_custom_target(run)
add_dependencies(run test)
add_custom_command(
    TARGET run
    POST_BUILD
    COMMAND test
    COMMENT "RUN test..."
)