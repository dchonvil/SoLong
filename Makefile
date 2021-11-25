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

MK = make

CC = clang

RM = rm -rf

LIB = libft.a

MLX = libmlx.a

NAME = so_long

SPATH = ./srcs/

INC_PATH = ./inc/

MLX_PATH = ./mlx/

LIB_PATH = ./libft/

SRC = $(SPATH)game.c \
	$(SPATH)drawer.c \
	$(SPATH)solong.c \
	$(SPATH)map_mng.c \
	$(SPATH)file_mng.c \
	$(SPATH)wind_mng.c

HEAD_PATH = -I inc -I mlx

LDFLAGS = $(LIB_PATH)$(LIB) $(MLX_PATH)$(MLX)

MLXFLAGS = -lm -lXext -lX11

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

OBJ_DIR = mkdir obj && mv *.o obj

.c.o:
	$(CC) $(CFLAGS) $(HEAD_PATH) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(MK) -C mlx
	$(MK) -C libft
	$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(MLXFLAGS) $(LDFLAGS) $(HEAD_PATH)
	(cd $(SPATH) && $(OBJ_DIR))

clean:
	$(MK) clean -C libft
	(cd $(SPATH) && $(RM) obj)
	(cd $(MLX_PATH) && $(RM) obj)

fclean: clean
	$(RM) $(NAME)
	$(MK) clean -C mlx
	$(MK) fclean -C libft

re: fclean all

