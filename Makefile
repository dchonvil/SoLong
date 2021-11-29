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

BPATH = ./bonus/

INC_PATH = ./inc/

MLX_PATH = ./mlx/

LIB_PATH = ./libft/

SRC = $(SPATH)game.c \
	$(SPATH)drawer.c \
	$(SPATH)solong.c \
	$(SPATH)map_mng.c \
	$(SPATH)file_mng.c \
	$(SPATH)wind_mng.c

SRC_BNS = $(BPATH)game_bonus.c \
	$(BPATH)drawer_bonus.c \
	$(BPATH)solong_bonus.c \
	$(BPATH)map_mng_bonus.c \
	$(BPATH)file_mng_bonus.c \
	$(BPATH)wind_mng_bonus.c

HEAD_PATH = -I inc -I mlx -I libft/inc

LDFLAGS = $(LIB_PATH)$(LIB) $(MLX_PATH)$(MLX)

MLXFLAGS = -lm -lXext -lX11

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

OBJ_BNS = $(SRC_BNS:.c=.o)

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
	(cd $(BPATH) && $(RM) obj)
	(cd $(MLX_PATH) && $(RM) obj)

fclean: clean
	$(RM) $(NAME)
	$(MK) clean -C mlx
	$(MK) fclean -C libft

bonus: fclean $(OBJ_BNS)
	$(MK) -C mlx
	$(MK) -C libft
	$(CC) $(SRC_BNS) -o $(NAME) $(CFLAGS) $(MLXFLAGS) $(LDFLAGS) $(HEAD_PATH)
	(cd $(BPATH) && $(OBJ_DIR))

re: fclean all

