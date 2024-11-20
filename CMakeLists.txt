cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
    add_compile_options(-Wall -Wextra -Wpedantic -Wshadow)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compile_options(/WX /W3 /permissive-)
    add_compile_options(/MP)
endif ()

project(Simple_Cpp_Project_Template VERSION 0.1)

configure_file(public/ProjectConfig.h.in ProjectConfig.h)

add_executable(Simple_Cpp_Project_Template private/main.cpp)

target_include_directories(Simple_Cpp_Project_Template PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/public"
)

target_include_directories(Simple_Cpp_Project_Template PRIVATE
        "${PROJECT_SOURCE_DIR}/private"
)