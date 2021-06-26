cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# Set up the project
project(redfish
    VERSION 1.0.0 
    LANGUAGES C
)

add_library(${PROJECT_NAME})
add_library("simple_redfish::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC 
    "simple_redfish::http"
    "simple_redfish::rest"
)

#aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/ _SRC)
target_sources(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/redfish_root.c
    ${CMAKE_CURRENT_LIST_DIR}/redfish_systems.c
    #${CMAKE_CURRENT_LIST_DIR}/redfish_managers.c
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}
)