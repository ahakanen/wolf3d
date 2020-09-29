# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 18:51:12 by ahakanen          #+#    #+#              #
#    Updated: 2020/09/10 12:35:28 by ahakanen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = graphics.a

SRC = dotp.c drawcircle.c drawdot.c drawline.c drawrect.c drawstraight.c \
		ft_abs.c ft_fracpart.c ft_sqrt.c ft_sqrtn.c g_init.c g_init2.c \
		g_memcpy.c transmat.c matxmat.c matxvec.c polyline.c polyline2.c \
		polyline3.c polylineshapes.c reverseline.c rotmat.c scalemat.c \
		slope.c vlen.c vecadd.c

INCLUDES = /includes/

OUT = dotp.o drawcircle.o drawdot.o drawline.o drawrect.o drawstraight.o \
		ft_abs.o ft_fracpart.o ft_sqrt.o ft_sqrtn.o g_init.o g_init2.o \
		g_memcpy.o transmat.o matxmat.o matxvec.o polyline.o polyline2.o \
		polyline3.o polylineshapes.o reverseline.o rotmat.o scalemat.o \
		slope.o vlen.o vecadd.o

all: $(NAME)

$(NAME):
	gcc -Werror -Wextra -Wall -c $(SRC) -I $(INCLUDES)
	ar rc $(NAME) $(OUT)

clean:
	rm -f $(OUT)

fclean: clean
	rm -f $(NAME)

re: fclean all
