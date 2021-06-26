cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# Set up the project
project(test
    VERSION 1.0.0
)

add_executable(${PROJECT_NAME} "")

target_sources(${PROJECT_NAME}
    PRIVATE
    test.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    pcre
    r3
    http
    rest
    -Wl,--whole-archive
    redfish
    -Wl,--no-whole-archive
)

add_dependencies(${PROJECT_NAME} 
    pcre
    r3
    http
    rest
    redfish
)