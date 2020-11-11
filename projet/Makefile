NAME = cub3D

LIBFT = libft.a

MLXD = bibz/minilibx-linux/

CUBD= bibz/libcub.a

LIBFTD = fct/libft/

INCL = bibz

COMPILE = gcc

CFLAGS = -Wall -Wextra -Werror

MINILIBIX =	minilibx-linux/mlx_clear_window.o \
            minilibx-linux/mlx_destroy_image.o \
            minilibx-linux/mlx_destroy_window.o  \
            minilibx-linux/mlx_expose_hook.o  \
            minilibx-linux/mlx_flush_event.o  \
            minilibx-linux/mlx_get_color_value.o \
            minilibx-linux/mlx_get_data_addr.o  \
            minilibx-linux/mlx_hook.o \
            minilibx-linux/mlx_init.o  \
            minilibx-linux/mlx_int_anti_resize_win.o \
            minilibx-linux/mlx_int_do_nothing.o  \
            minilibx-linux/mlx_int_get_visual.o \
            minilibx-linux/mlx_int_param_event.o \
            minilibx-linux/mlx_int_set_win_event_mask.o \
            minilibx-linux/mlx_int_str_to_wordtab.o \
            minilibx-linux/mlx_int_wait_first_expose.o \
            minilibx-linux/mlx_key_hook.o \
            minilibx-linux/mlx_loop.o  \
            minilibx-linux/mlx_loop_hook.o \
            minilibx-linux/mlx_mouse_hook.o \
            minilibx-linux/mlx_new_image.o \
            minilibx-linux/mlx_new_window.o \
            minilibx-linux/mlx_pixel_put.o \
            minilibx-linux/mlx_put_image_to_window.o \
            minilibx-linux/mlx_rgb.o \
            minilibx-linux/mlx_string_put.o \
            minilibx-linux/mlx_xpm.o \

SRC =		./doss/main.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(COMPILE) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ) doss/main.c
		rm -rf $(NAME)
		make -C $(MLXD)
		make -C $(LIBFTD)
		cp $(LIBFTD)$(LIBFT) ./$(CUBD)
		ar rc $(CUBD) $(OBJ)
		/bin/rm -f $(LIBFT)
		ranlib $(CUBD)
		$(COMPILE) -g3 -fsanitize=address -o $(NAME) __resources/main.c $(MINILIBIX) $(CUBD) -I$(INCL) -lm  -lXext -lX11 -lbsd

clean:
	rm -rf $(OBJ)
	rm -rf objects
	make clean -C $(LIBFTD)
	make clean -C $(MLXD)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	rm -rf $(CUBD)
	make fclean -C $(LIBFTD)

re: fclean all

.PHONY: clean fclean all re cub3D