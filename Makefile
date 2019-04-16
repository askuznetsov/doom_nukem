NAME = wolf3d

SRC_WOLF = ./src/main.c \
			./src/get_next_line.c \
			./src/ft_valid.c \
			./src/valid_help.c \
			./src/valid_help_2.c \
			./src/game.c \
			./src/sdl.c \
			./src/draw_map.c \
			./src/ft_fps.c \
			./src/keys.c \
			./src/keys_2.c \
			./src/raycast.c \
			./src/raycast_2.c \
			./src/ft_init_varible.c \

OBJECT_WOLF = $(SRC_WOLF:.c=.o)

FLAGS = -Wall -Wextra -Werror

INCLUDES_WOLF = -I ./include/

INCLUDES_LIBFT = -I ./lib/libft/

INCLUDES_SDL2 = -I ./lib/SDL/SDL2.framework/Headers

INCLUDES_SDL2_IMAGE = -I ./lib/SDL/SDL2_image.framework/Headers

INCLUDES_SDL2_MIXER = -I ./lib/SDL/SDL2_mixer.framework/Headers

LIBFT = ./lib/libft/libft.a

INCLUDES_SDL2_TTF = -I ./lib/SDL/SDL2_ttf.framework/Headers

FRAMEWORK_SDL2 = -F ./lib/SDL -framework SDL2 \
	-framework SDL2_image \
	-framework SDL2_ttf \
	-framework SDL2_mixer

FF = SDL2 \
	SDL2_image \

FRAMEWORK_MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(OBJECT_WOLF)
	make -C ./lib/libft
	@echo "file compiled"
	@gcc -o $(NAME) $(FLAGS) $(LIBFT) $(INCLUDES_SDL2) $(INCLUDES_SDL2_IMAGE) -rpath @loader_path/lib/sdl $(FRAMEWORK_SDL2) $(OBJECT_WOLF) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

%.o: %.c includes/*.h
	gcc -g $(FLAGS) -o $@ -c $< $(INCLUDES_WOLF) $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

%.o: %.c
	gcc -g 	$(FLAGS) -o $@ -c $< $(INCLUDES_WOLF) $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

	@echo "Wolf compiled"
clean:
	make -C ./lib/libft clean
	/bin/rm -f $(OBJECT_WOLF)
	rm -f TAGS

fclean: clean
	/bin/rm -f ./lib/libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all