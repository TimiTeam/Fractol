NAME = fractol

DIR_SRC = ./src/

DIR_OBJ = ./obj/

FILES = burning_sheep.c color_functions.c exit_and_close.c fractol_state.c guess_button.c julia.c main.c mouse_ivents.c my_fract.c run_fractal.c validation.c mandelbeot.c

FLAGS = -Wall -Wextra -Werror

O_FLAGS = -pipe -flto -pipe -Ofast -mtune=nativels

LIB_FT = -I libft/includes -L libft -lft

MLX_LIB = -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit 

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	make -C minilibx_macos/
	clang $(FLAGS) -c $(addprefix $(DIR_SRC), $(FILES)) $(O_FLAGS)
	mkdir -p obj
	mv $(OBJ) $(DIR_OBJ)
	clang $(FLAGS) -lpthread $(addprefix $(DIR_OBJ), $(OBJ)) $(LIB_FT) $(MLX_LIB) -o $(NAME)

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean
	/bin/rm -rf $(DIR_OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -rf $(NAME)

re: fclean all
