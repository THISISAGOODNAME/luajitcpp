cmake_minimum_required(VERSION 3.7)
project(luajittest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(luajit/include/luajit-2.1)

add_library(luajit SHARED IMPORTED)
set_property(TARGET luajit  PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/luajit/lua51.dll)
set_property(TARGET luajit  PROPERTY IMPORTED_IMPLIB ${CMAKE_CURRENT_SOURCE_DIR}/luajit/lua51.dll)
file(COPY luajit/lua51.dll DESTINATION ${CMAKE_BINARY_DIR}/)

set(SOURCE_FILES main.cpp)
add_executable(luajittest ${SOURCE_FILES})
target_link_libraries(luajittest luajit)