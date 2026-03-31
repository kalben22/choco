##
## EPITECH PROJECT, 2025
## makefile
## File description:
## write the makefile of this functions
##

NAME	=	mysh

SRCS	=	src/my_strcat.c \
		src/my_strcmp.c \
		src/my_strlen.c \
		src/my_strcpy.c \
		src/test.c \
		src/my_mini_printf.c \
		src/my_str_to_words_array.c \
		src/my_strdup.c \
		src/execute_func.c \
		src/func_to_free.c \
		src/exec_cmd.c \
		src/exec_process.c \
		src/setenv.c \
		src/my_strncmp.c \
		src/new_env.c \
		src/check_setenv.c \
		src/unsetenv.c \
		src/cleanstr.c

OBJS	=	$(SRCS:.c=.o)

CC	=	clang -g3

all: $(NAME)

$(NAME): $(SRCS)
	 $(CC) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)
re: fclean all

unit_tests: fclean $(NAME)
	clang -o unit_tests src/my_mini_printf.c test/uni_test.c --coverage -lcriterion

tests_run: unit_tests
	./unit_tests
