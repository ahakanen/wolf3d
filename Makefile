# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 05:19:03 by ahakanen          #+#    #+#              #
#    Updated: 2020/10/22 13:39:20 by ahakanen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBF = ./libft/
LIB = ./libft/libft.a
GRAPHIC = ./graphics/
GRAPHICL = ./graphics/graphics.a
MINI = -I /usr/local/include -L /usr/local/lib/ -lmlx -lX11 -lXext -lm \
		-lpthread
HEADER_PATH = ./header/
SRC = main.c help.c validate.c savemap.c initplayerstart.c openwindow.c \
		deal_key.c movement.c render.c raycheck.c drawminimap.c \
		minimapblocks.c rotarr.c drawsky.c drawfloor.c threadhelp.c \
		renderloop.c collision.c loadtexture.c parseblock.c initblocks.c \
		texturewall.c raycasttextures.c initblocks2.c

all: $(NAME)

$(NAME):
	make -C $(LIBF)
	make -C $(GRAPHIC)
	$(CC) -o $(NAME) $(SRC) $(LIB) $(GRAPHICL) -I $(HEADER_PATH) $(MINI)

clean:
	make -C $(LIBF) clean
	make -C $(GRAPHIC) clean

fclean:
	rm -rf $(NAME)
	make -C $(LIBF) fclean
	make -C $(GRAPHIC) fclean

re: fclean all

.PHONY: all clean fclean re
