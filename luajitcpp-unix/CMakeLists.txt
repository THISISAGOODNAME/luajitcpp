cmake_minimum_required(VERSION 3.5)
project(luajitcpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pagezero_size 10000 -image_base 100000000")
endif()

include(ExternalProject)

ExternalProject_Add(project_luajit
        URL http://luajit.org/download/LuaJIT-2.1.0-beta2.tar.gz
        URL_MD5 fa14598d0d775a7ffefb138a606e0d7b
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/luajit-2.1.0-beta2
        UPDATE_COMMAND ""
        CONFIGURE_COMMAND ""
        BUILD_COMMAND make PREFIX=${CMAKE_CURRENT_BINARY_DIR}/luajit-2.1.0-beta2
        BUILD_IN_SOURCE 1
        INSTALL_COMMAND make install PREFIX=${CMAKE_CURRENT_BINARY_DIR}/luajit-2.1.0-beta2
        )

ExternalProject_Get_Property(project_luajit install_dir)


add_library(luajit STATIC IMPORTED)
set_property(TARGET luajit PROPERTY IMPORTED_LOCATION ${install_dir}/lib/libluajit-5.1.a)
add_dependencies(luajit project_luajit)

include_directories(${install_dir}/include/luajit-2.1)

# 1. luajit REPL
add_executable(luajitrepl src/luajitCli.cpp)
target_link_libraries(luajitrepl luajit)

# 2. luajit 读取lua文件并运行
add_executable(luajitluafromfile src/luajitLoadLuaFile.cpp)
target_link_libraries(luajitluafromfile luajit)
file(COPY version.lua DESTINATION ${CMAKE_BINARY_DIR}/)



