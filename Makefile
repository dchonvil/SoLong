# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 12:35:41 by dchonvil          #+#    #+#              #
#    Updated: 2021/07/30 04:57:50 by dchonvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Werror -Wextra //clang *.c libft.a libmlx.a -lm -lXext -lX11

PROG = so_long

LIB = libft.a

LIB_PATH = ./libft/

MLX = libmlx_Linux.a

MLX_PATH = ./mlx/

HEAD_PATH = ./inc/

NAME = $(MLX) $(LIB) $(PROG)

SRC = *.c

SRC_PATH = ./srcs/

SRC-BNS1 = Bonus/Server_repo/server.c

SRC-BNS2 = Bonus/Client_repo/client.c \
		Bonus/Client_repo/utils_client.c

OBJ = $(SRC:.c=.o)

OBJ-BNS1 = $(SRC-BNS1:.c=.o)

RM = rm -rf

MK = make

all: $(NAME)

$(MLX):
	(cd $(MLX_PATH) && $(MK))

$(LIB):
	(cd $(LIB_PATH) && $(MK))

$(PROG): $(OBJ)
	$(CC) $(SRC_PATH)$(SRC) -o $(PROG) $(CFLAGS) $(LIB_PATH)$(LIB) -I$(HEAD_PATH)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ-BNS1)
	(cd libft && $(MK) clean)

fclean: clean
	$(RM) $(NAME)
	(cd libft && $(MK) fclean)

re: fclean all

bonus: fclean $(OBJ-BNS1) $(OBJ-BNS2) $(LIB)
	$(CC) Bonus/Server_repo/server.c -o server $(CFLAGS) ./libft/libft.a -I./

