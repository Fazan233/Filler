cmake_minimum_required(VERSION 3.12)
# Name of project and its options
project(Filler LANGUAGES C)
# Set standart for C language
set(CMAKE_C_STANDARD 99)
# Specify the folder to be executed CMakeFiles.txt
add_subdirectory(./libft)
add_subdirectory(./visualizator)
# Create executable and add sourses to its
#AUX_SOURCE_DIRECTORY(./ FILLER_SRCS)
set(FILLER_SRCS filler.c free_2d_char.c get_real_token_size.c put_token.c)
add_executable(vuslysty.filler ${FILLER_SRCS})
#target_compile_options(Filler PUBLIC -Wall -Wextra -Werror)
target_include_directories(vuslysty.filler PUBLIC ./includes)
# Add library to executable
target_link_libraries(vuslysty.filler LIBFT)
