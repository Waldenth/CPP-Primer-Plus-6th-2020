cmake_minimum_required(VERSION 3.5)

# Set the project name
project (vcpkg_opencv_test)

SET(CMAKE_TOOLCHAIN_FILE "D:/src/vcpkg/scripts/buildsystems/vcpkg.cmake")

# find a boost install with the libraries filesystem and system
#使用库文件系统和系统查找boost install
#find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)
#这是第三方库，而不是自己生成的静态动态库
# check if boost was found


# Add an executable
add_executable(vcpkg_opencv_test main.cpp)

# link against the boost libraries
