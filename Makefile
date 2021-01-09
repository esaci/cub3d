NAME = cub3D

LIBFT = libft.a

FTPRINTF = libftprintf.a

MLXD = fct/minilibx-linux/

CUBD= bibz/libcub.a

LIBFTD = fct/libft/

FTPRINTFD = fct/ft_printf/

INCL = bibz

COMPILE = gcc

CFLAGS = -Wall -Wextra -Werror

MINILIBIX =	$(MLXD)/mlx_clear_window.o \
            $(MLXD)/mlx_destroy_image.o \
            $(MLXD)/mlx_destroy_window.o  \
            $(MLXD)/mlx_expose_hook.o  \
            $(MLXD)/mlx_flush_event.o  \
            $(MLXD)/mlx_get_color_value.o \
            $(MLXD)/mlx_get_data_addr.o  \
            $(MLXD)/mlx_hook.o \
            $(MLXD)/mlx_init.o  \
            $(MLXD)/mlx_int_anti_resize_win.o \
            $(MLXD)/mlx_int_do_nothing.o  \
            $(MLXD)/mlx_int_get_visual.o \
            $(MLXD)/mlx_int_param_event.o \
            $(MLXD)/mlx_int_set_win_event_mask.o \
            $(MLXD)/mlx_int_str_to_wordtab.o \
            $(MLXD)/mlx_int_wait_first_expose.o \
            $(MLXD)/mlx_key_hook.o \
            $(MLXD)/mlx_loop.o  \
            $(MLXD)/mlx_loop_hook.o \
            $(MLXD)/mlx_mouse_hook.o \
            $(MLXD)/mlx_new_image.o \
            $(MLXD)/mlx_new_window.o \
            $(MLXD)/mlx_pixel_put.o \
            $(MLXD)/mlx_put_image_to_window.o \
            $(MLXD)/mlx_rgb.o \
            $(MLXD)/mlx_string_put.o \
            $(MLXD)/mlx_xpm.o \

SRC =		./doss/init.c \
			./doss/maptest.c \
			./doss/mapper.c \
			./doss/reader.c \
			./doss/main.c \
			./doss/player.c \
			./doss/fct.c \
			./doss/draw.c \
			./doss/draw2.c \
			./doss/utils.c \
			./doss/utils2.c \
			./doss/utils3.c \
			./doss/rcast.c \
			./doss/setup.c \
			./doss/depart.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(COMPILE) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ) doss/main.c
		rm -rf $(NAME)
		make -C $(MLXD)
		make -C $(LIBFTD)
		make -C $(FTPRINTFD)
		cp $(LIBFTD)$(LIBFT) ./$(CUBD)
		cp $(FTPRINTFD)$(FTPRINTF) ./$(CUBD)
		ar rc $(CUBD) $(OBJ)
		/bin/rm -f $(LIBFT)
		/bin/rm -f $(FTPRINTF)
		ranlib $(CUBD)
		$(COMPILE) -g3 -fsanitize=address -o $(NAME) doss/main.c $(MINILIBIX) $(CUBD) -I$(INCL) -lm  -lXext -lX11 -lbsd

clean:
	rm -rf $(OBJ)
	rm -rf objects
	make clean -C $(LIBFTD)
	make clean -C $(MLXD)
	make clean -C $(FTPRINTFD)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	rm -rf $(CUBD)
	rm -rf $(FTPRINTF)
	make fclean -C $(LIBFTD)
	make fclean -C $(FTPRINTFD)

re: fclean all

.PHONY: clean fclean all re