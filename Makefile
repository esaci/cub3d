NAME = cub3D

LIBFT = libft.a

FTPRINTF = libftprintf.a

MLXD = fct/minilibx-linux/

SRCD = ./src

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
			$(MLXD)/mlx_screen_size.o  \

SRC =		$(SRCD)/init.c \
			$(SRCD)/maptest.c \
			$(SRCD)/mapper.c \
			$(SRCD)/reader.c \
			$(SRCD)/main.c \
			$(SRCD)/player.c \
			$(SRCD)/fct.c \
			$(SRCD)/draw.c \
			$(SRCD)/draw2.c \
			$(SRCD)/utils.c \
			$(SRCD)/utils2.c \
			$(SRCD)/utils3.c \
			$(SRCD)/rcast.c \
			$(SRCD)/debut.c \
			$(SRCD)/chargement.c \
			$(SRCD)/bmp.c \
			$(SRCD)/bmp2.c \
			$(SRCD)/remplir.c \
			./fct/GNL/get_next_line.c \
			./fct/GNL/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(COMPILE) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ) $(SRCD)/main.c
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
		$(COMPILE) -g3  -o $(NAME) $(SRCD)/main.c $(MINILIBIX) $(CUBD) -I$(INCL) -lm  -lXext -lX11 -lbsd

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
