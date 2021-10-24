cmake_minimum_required(VERSION 3.5)#最低CMake版本

project (DFA)# 工程名

set(PROJECT_Binary_DIR $(PROJECT_SOURCE_DIR)/bin)

set(SOURCES
    src/DFA.cpp
    src/main.cpp
)#创建一个变量，名字叫SOURCE。它包含了所有的cpp文件。

add_executable(DFA ${SOURCES})#用所有的源文件生成一个可执行文件，因为这里定义了SOURCE变量，所以就不需要罗列cpp文件了
#等价于命令：     add_executable(DFA src/Hello.cpp src/main.cpp)

target_include_directories(DFA
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)#设置这个可执行文件DFA需要包含的库的路径
 
 
#PROJECT_SOURCE_DIR指工程顶层目录
#PROJECT_Binary_DIR指编译目录
#PRIVATE指定了库的范围，下一节讲