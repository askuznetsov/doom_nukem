cmake_minimum_required(VERSION 3.13)
project(Doom C)

set(CMAKE_C_STANDARD 99)

include_directories(/Users/tvoronyu/CLionProjects/Doom/include)

#source_group(src)


include_directories(lib/SDL/SDL2.framework/Headers)
include_directories(lib/SDL/SDL2_image.framework/Headers)
include_directories(lib/SDL/SDL2_mixer.framework/Headers)
include_directories(lib/SDL/SDL2_ttf.framework/Headers)
include_directories(lib/libft/libft.h)

#include_directories(/Users/tvoronyu/CLionProjects/untitled7)


add_executable(Doom src/main.c)
#add_library(untitled7 src/game.c)
#add_subdirectory(untitled7/src)
#source_group(src/game.c)
#add_subdirectory(src)
#add_executable(untitled7 src/game.c)
#add_executable(untitled7 src/ft_fps.c)
#add_executable(untitled7 src/ft_init_varible.c)
#add_executable(untitled7 src/ft_valid.c)
#add_executable(untitled7 src/valid_help.c)
#add_executable(untitled7 src/valid_help_2.c)
#add_executable(untitled7 src/draw_map.c)
#add_executable(untitled7 src/sdl.c)
#add_executable(untitled7 src/get_next_line.c)
#add_executable(untitled7 src/keys.c)
#add_executable(untitled7 src/keys_2.c)
#add_executable(untitled7 src/raycast.c)
#add_executable(untitled7 src/raycast_2.c)