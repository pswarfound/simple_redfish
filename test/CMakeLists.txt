cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# Set up the project
project(test
    VERSION 1.0.0 
    LANGUAGES C
)

link_directories(
    ${PROJECT_SOURCE_DIR}/../lib/${ARCH}
)

add_executable(${PROJECT_NAME} "")

target_sources(${PROJECT_NAME}
    PRIVATE
    test.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/../include
    ${PROJECT_SOURCE_DIR}/../include/pcre
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -Wl,--whole-archive
    http
    rest
    redfish
    -Wl,--no-whole-archive
    r3
    pcre
)

add_dependencies(${PROJECT_NAME} 
    http
    rest
    redfish
)