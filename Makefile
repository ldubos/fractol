# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/20 10:21:26 by ldubos            #+#    #+#              #
#    Updated: 2016/05/25 10:31:04 by ldubos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export CFLAGS=-Wall -Wextra -Werror -Ofast -o3
NAME=fractol
MLX=-lmlx -framework OpenGL -framework AppKit
SRCS_DIR=srcs/
SRCS=$(SRCS_DIR)main.c \
	 $(SRCS_DIR)error.c \
	 $(SRCS_DIR)basic_draw.c \
	 $(SRCS_DIR)julia.c \
	 $(SRCS_DIR)mandelbrot.c \
	 $(SRCS_DIR)draw.c \
	 $(SRCS_DIR)hook.c
OBJS=$(SRCS:.c=.o)
	INC_DIR=-I./includes/ -I./libft/includes/
	LIB_DIR=-L./libft -lft $(MLX)
	LIB_MAKE=libft/

all		: $(NAME)

$(NAME) : $(OBJS)
	@cd $(LIB_MAKE) && $(MAKE)
	@printf "\033[1;33m[Fractol all]\t\t\033[1;32m.\033[0;02m";
	@gcc $(CFLAGS) $(OBJS) -o $(NAME) $(LIB_DIR) $(LFLAGS)
	@printf "\033[1;32m.\t\t[OK]\033[0;02m\n";

%.o		: %.c
	@gcc $(CFLAGS) $(INC_DIR) -c $< -o $@

.PHONY	: clean fclean clr re

clean	:
	@cd $(LIB_MAKE) && $(MAKE) $@
	@printf "\033[1;33m[Fractol clean]\t\t\033[1;32m.\033[0;02m";
	@rm -f $(OBJS)
	@printf "\033[1;32m.\t\t[OK]\033[0;02m\n";

fclean	:
	@cd $(LIB_MAKE) && $(MAKE) $@
	@printf "\033[1;33m[Fractol fclean]\t\033[1;32m.\033[0;02m";
	@rm -f $(NAME)
	@printf "\033[1;32m.\t\t[OK]\033[0;02m\n";

clr		: fclean clean

re		: fclean all
