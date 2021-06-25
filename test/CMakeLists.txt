cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# Set up the project
project(test
    VERSION 1.0.0 
    LANGUAGES C
)

add_executable(${PROJECT_NAME} "")

target_sources(${PROJECT_NAME}
    PRIVATE
    test.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${LIBSYSTEM_INC_DIR}
    ${LIBHAL_INC_DIR}
)

link_directories(
    ${PROJECT_BINARY_DIR}/lib
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -Wl,--whole-archive
    http
    rest
    redfish
    -Wl,--no-whole-archive
)

add_dependencies(${PROJECT_NAME} 
    http
    rest
    redfish
)