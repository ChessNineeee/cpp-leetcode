cmake_minimum_required(VERSION 3.16)
project(cpp_leetcode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 指定编译器为g++
set(CMAKE_CXX_COMPILER g++)
set(CPPCHECK_EXECUTABLE "/home/zhengqi/cppcheck/build/bin/cppcheck")
# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_compile_options(-Wall -Werror -Wextra)

find_package(fmt)

# 创建一个变量来存储所有的.cpp文件
file(GLOB SOURCES "src/*.cpp")

# 遍历.cpp文件列表，为每个文件创建一个可执行程序
foreach(SOURCE ${SOURCES})
    # 获取.cpp文件的文件名（不包含路径和扩展名）
    get_filename_component(PROGRAM_NAME ${SOURCE} NAME_WE)
    message(${PROGRAM_NAME})
    # 添加可执行程序
    add_executable(${PROGRAM_NAME} ${SOURCE})
    target_link_libraries(${PROGRAM_NAME} fmt::fmt)
    add_custom_command(TARGET ${PROGRAM_NAME}
        POST_BUILD
        COMMAND ${CPPCHECK_EXECUTABLE} --enable=all --suppress=missingIncludeSystem --std=c++17 --force  --project=compile_commands.json
        COMMENT "Running cppcheck after build"
    )
endforeach()



