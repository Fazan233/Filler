cmake_minimum_required(VERSION 3.12)
project(Filler LANGUAGES C)

add_subdirectory(./libft)
add_executable(Filler main.c)
target_link_libraries(Filler LIBFT)
install(TARGETS Filler DESTINATION ./bin) 