# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 14:58:40 by lvogelsa          #+#    #+#              #
#    Updated: 2023/01/10 15:27:43 by lvogelsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = errors.c map.c player.c score.c so_long.c sprites.c utils.c

MLX_PATH = ./mlx
MLX = $(MLX_PATH)/libmlx.a
MLX_COMP = -L mlx -l mlx -framework OpenGL -framework AppKit

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX_COMP) -o $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean: clean
		make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME)
	
re: fclean all
