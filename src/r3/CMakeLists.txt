cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# Set up the project
project(r3
    VERSION 2.0.0
)

set(CMAKE_C_STANDARD 99)

include(CheckSymbolExists)
check_symbol_exists(strdup string.h HAVE_STRDUP)
check_symbol_exists(strndup string.h HAVE_STRNDUP)
configure_file(config.h.cmake config.h)

add_library(${PROJECT_NAME})
add_library("simple_redfish::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    pcre
)

target_sources(${PROJECT_NAME}
    PRIVATE
    src/edge.c
    src/match_entry.c
    src/memory.c
    src/node.c
    src/slug.c
    src/str.c
    src/token.c
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    _GNU_SOURCE)

target_include_directories(${PROJECT_NAME} 
    PUBLIC
    ${PROJECT_BINARY_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${PROJECT_SOURCE_DIR}/../../include
    ${PROJECT_SOURCE_DIR}/../../include/pcre
)