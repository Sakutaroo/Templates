##
## EPITECH PROJECT, %YEAR
## Makefile
## File description:
## Makefile
##

SRC_MAIN	=	src/main.c

SRC	=	src/%BINARY_NAME.c

SRC_TEST	=	tests/test_%BINARY_NAME.c

NAME	=	%BINARY_NAME

NAME_TEST	=	unit_tests

OBJ	=	$(SRC_MAIN:.c=.o) $(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

LDLIBS	=	-lcriterion -lgcov --coverage

all: $(NAME)

$(NAME):	$(OBJ)
\\t$(CC) $(OBJ) -o $(NAME)

clean:
\\trm -f $(OBJ)
\\trm -f $(OBJ_TEST)
\\tfind . -name "*~" -delete
\\tfind . -name '#'*'#' -delete
\\tfind . -name '*.gc*' -delete

fclean: clean
\\trm -f $(NAME)
\\trm -f $(NAME_TEST)

re: fclean all

tests_run: fclean
\\t$(CC) -o $(NAME_TEST) $(SRC) $(SRC_TEST) $(LDLIBS) $(CPPFLAGS)
\\t./unit_tests

gcovr:
\\tgcovr . --exclude=tests/

debug: fclean
debug: CFLAGS += -ggdb3
debug: all

.PHONY: all clean fclean fclean re tests_run gcovr debug
