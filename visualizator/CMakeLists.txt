cmake_minimum_required(VERSION 3.12)
# Name of project and its options
project(map_filter LANGUAGES C)
# Set standart for C language
set(CMAKE_C_STANDARD 99)
# Create executable and add sourses to its
add_executable(map_filter map_filter.c)
#target_compile_options(Filler PUBLIC -Wall -Wextra -Werror)
target_include_directories(map_filter PUBLIC ../includes)
# Add library to executable
target_link_libraries(map_filter LIBFT)
