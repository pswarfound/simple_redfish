cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# Set up the project
project(http
    VERSION 1.0.0 
    LANGUAGES C
)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/ _SRC)

add_library(${PROJECT_NAME})
add_library("simple_redfish::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    ${_SRC}
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}
)
