cmake_minimum_required(VERSION 3.5)
project(hello_library)
############################################################
# Create a library
############################################################
#库的源文件Hello.cpp生成静态库hello_library
add_library(hello_library STATIC 
    src/Hello.cpp
)
# target_include_directories为一个目标（可能是一个库library也可能是可执行文件）添加头文件路径
# 这里是为生成目标hello_library添加头文件目录,并设置该目录为PUBLIC
target_include_directories(hello_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)


############################################################
# Create an executable
############################################################
# Add an executable with the above sources
#指定用哪个源文件生成可执行文件hello_binary
add_executable(hello_binary 
    src/main.cpp
)

#链接可执行文件和静态库
#在链接期间将hello_library链接到hello_binary可执行文件
#hello_library有PUBLIC属性的目录, 
#这个被链接的库如果有INTERFACE或者PUBLIC属性的包含目录,那么,这个包含目录也会被传递(propagate)给这个可执行文件。
target_link_libraries( hello_binary
    PRIVATE 
        hello_library
)

#链接库和包含头文件目录都有关于scope这三个关键字的用法。

# 包含头文件目录 target_include_directories
# PRIVATE - 目录被添加到目标（库）的包含路径中。
# INTERFACE - 目录没有被添加到目标（库）的包含路径中，而是链接了这个库的其他目标（库或者可执行程序）包含路径中
# PUBLIC - 目录既被添加到目标（库）的包含路径中，同时添加到了链接了这个库的其他目标（库或者可执行程序）的包含路径中

# 链接库 target_link_libraries
# PUBLIC - 你的这个工程(hello_binary)如果被link了，那你的target_link_libraries指定的lib(hello_library)也会被链接
# PRIVATE - 工程如果被link, 这个工程的link libs不会被暴露出去
# 比如你的工程B是个dll，且public的连接了C, D 这个时候你的A.exe要链接B，那么它也会链接C和D 如果B是private链接了C, D 那么A链B的时候，不会链C和D
# 对于hello_binary，它不是库，所以不会被链接。直接private自己用这个库就行。
