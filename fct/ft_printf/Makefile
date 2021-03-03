# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esaci <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/02 23:46:49 by esaci             #+#    #+#              #
#    Updated: 2020/08/08 16:22:41 by esaci            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

DIR_LIBFT = ./libft/

SRC = fctc.c \
      fctprc.c \
      fctze.c \
      fnct4.c \
      lecture.c \
      fctd.c \
      fcts.c \
      fnct.c \
      ft_parsers.c \
      structure.c \
      fcti.c \
      fctu.c \
      fnct2.c \
      ft_printf.c \
      fctp.c \
      fctx.c \
      fnct3.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		make -C $(DIR_LIBFT)
		cp $(DIR_LIBFT)$(LIBFT) ./$(NAME)
		ar rc $(NAME) $(OBJ)
		/bin/rm -f $(LIBFT)
		ranlib $(NAME)
%.o: %.c
	gcc $(FLAG) -c $< -o $@

test:
	gcc main.c libftprintf.a -g3 -fsanitize=address

ftest:
	make clean
	make
	make test

clean:
	rm -f $(OBJ)
	make clean -C $(DIR_LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C $(DIR_LIBFT)

re: fclean all

.PHONY: clean fclean all re

