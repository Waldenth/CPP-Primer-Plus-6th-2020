cmake_minimum_required(VERSION 3.5)#最低CMake版本

#set (CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -fexec-charset=GBK" CACHE STRING "Set C Compiler Flags" FORCE)
add_compile_options(-fexec-charset=GBK)

project (Prim)# 工程名


set(SOURCES
    src/Prim.c
    src/main.c
)#创建一个变量，名字叫SOURCE。它包含了所有的cpp文件。

add_executable(Prim ${SOURCES})#用所有的源文件生成一个可执行文件，因为这里定义了SOURCE变量，所以就不需要罗列c/cpp文件了

target_include_directories(Prim
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)#设置这个可执行文件Prim需要包含的库的路径




