SRC	=	main.cpp	\
		../FunctionPointer.cpp

NAME	=	function_pointer

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

CFLAGS	=	-Wall -Wextra -std=c++20

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
