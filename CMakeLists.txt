cmake_minimum_required(VERSION 3.16)
project(MySQL)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)

enable_testing ()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library (db_mysql "")
target_link_libraries(db_mysql ${CONAN_LIBS})
target_sources(db_mysql 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/src/db_mysql.c
    )
target_include_directories(db_mysql
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    )

add_subdirectory (test)