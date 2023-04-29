SRC	=	main.c	\
		function_pointer.c

NAME	=	function_pointer

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I../

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete
	find . -name '#'*'#' -delete
	find . -name '*.gc*' -delete

fclean: clean
	rm -f $(NAME)
	clear

re:	fclean all

debug: fclean
debug:	CFLAGS += -ggdb3
debug: all

exec:	debug
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(NAME)

.PHONY: all clean fclean re debug exec
