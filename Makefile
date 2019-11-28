##
## EPITECH PROJECT, 2019
## initiation
## File description:
## Makefile
##

SRC	=	main.c	\
		src/event.c	\
		src/hitler.c	\
		src/my_itoa.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_getnbr.c	\

CC	=	gcc -W -Wall -Wextra -g3

CFLAGS	=	-I./include/

AR	=	ar rc

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

NAME2	=	libbtree.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME2) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -L. -lbtree

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)

re:	fclean all