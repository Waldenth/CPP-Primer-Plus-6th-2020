cmake_minimum_required(VERSION 3.1)
project(SimpleNES)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

set(BUILD_STATIC FALSE CACHE STRING "Set this to link external libraries statically")

# 设置引入的外部第三方库的路径
set (EXTERNAL_DIR ${PROJECT_SOURCE_DIR}/external)
set (SFML_INCLUDE_DIR ${EXTERNAL_DIR}/SFML-2.5.1/include)
#set (SFML_LIBRARIES "sfml-window sfml-graphics sfml-audio sfml-system")
#set (SFML_ROOT ${EXTERNAL_DIR}/SFML-2.5.1)
#set (SFML_DIR ${EXTERNAL_DIR}/SFML-2.5.1/lib/cmake/SFML)
#set (SFML_LIBRARY_DIR ${EXTERNAL_DIR}/SFML-2.5.1/lib)




if(CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

#Add directory containing FindSFML.cmake to module path
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/;${CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR};${EXTERNAL_DIR}")
#message(${CMAKE_MODULE_PATH})

# SFML库的路径，要精确到官方下载的文件/lib/cmake/SFML
set (SFML_DIR ${EXTERNAL_DIR}/SFML-2.5.1/lib/cmake/SFML)
message(${SFML_DIR})


# Add sources
file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Copy keybindings.conf
file(COPY keybindings.conf DESTINATION .)

# Will add __FILENAME__ macros for all source files, which is the filename without full find_path
# Courtesy of SO
function(define_file_basename_for_sources targetname)
    get_target_property(source_files "${targetname}" SOURCES)
    foreach(sourcefile ${source_files})
        # Get source file's current list of compile definitions.
        get_property(defs SOURCE "${sourcefile}"
            PROPERTY COMPILE_DEFINITIONS)
        # Add the FILE_BASENAME=filename compile definition to the list.
        get_filename_component(basename "${sourcefile}" NAME)
        list(APPEND defs "__FILENAME__=\"${basename}\"")
        # Set the updated compile definitions on the source file.
        set_property(
            SOURCE "${sourcefile}"
            PROPERTY COMPILE_DEFINITIONS ${defs})
    endforeach()
endfunction()

# Specify include Directory
include_directories("${PROJECT_SOURCE_DIR}/include")

# Set static if BUILD_STATIC is set
if (BUILD_STATIC)
    set(SFML_STATIC_LIBRARIES TRUE)
    # Link libgcc and libstc++ statically as well
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
    endif()
endif()

# Find SFML
# 调用需要的模块，此项命令依赖于上面SFML_DIR路径的设置，对于SFML，项目用到啥 调用啥
if (SFML_OS_WINDOWS AND SFML_COMPILER_MSVC)
    find_package( SFML 2.5 COMPONENTS main audio graphics window system REQUIRED)
else()
    find_package( SFML 2.5 COMPONENTS audio graphics window system REQUIRED)
endif()

if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
else()
        set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
        message("\nSFML directory not found. Set SFML_ROOT to SFML's top-level path (containing \"include\" and \"lib\" directories).")
        message("Make sure the SFML libraries with the same configuration (Release/Debug, Static/Dynamic) exist.\n")
endif()


message(${SFML_INCLUDE_DIR})
#message(${SFML_LIBRARIES})

add_executable(SimpleNES ${SOURCES})
#target_link_libraries(SimpleNES ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
target_link_libraries(SimpleNES sfml-audio sfml-graphics sfml-window sfml-system)

set_property(TARGET SimpleNES PROPERTY CXX_STANDARD 11)
set_property(TARGET SimpleNES PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(SimpleNES)

# 将SFML/bin下的所有*.dll复制到 /build文件下，保证编译程序正常运行，不报缺少dll错误
file(GLOB_RECURSE PROJECT_DLL ${EXTERNAL_DIR}/*.dll)
message(${PROJECT_DLL})
# 复制库到工作目录
# POST_BUILD 在编译后操作
# copy命令拷贝单个文件，下面的 copy_directory是拷贝目录
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${PROJECT_DLL}
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

define_file_basename_for_sources(SimpleNES)