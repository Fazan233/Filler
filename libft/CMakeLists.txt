cmake_minimum_required(VERSION 3.12)
project(LIBFT LANGUAGES C)

AUX_SOURCE_DIRECTORY(./srcs LIB_SRCS)
AUX_SOURCE_DIRECTORY(./srcs/ft_printf PF_SRCS)

add_library(LIBFT STATIC ${LIB_SRCS} ${PF_SRCS})
target_include_directories(LIBFT PUBLIC ./includes)
target_compile_options(LIBFT PUBLIC -Wall -Wextra -Werror)
