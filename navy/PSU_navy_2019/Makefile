##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## for evalexpr
##

SRC_LIB		=	lib/my/additive.c \
		lib/my/base_flag_functions.c \
		lib/my/flag_functions.c \
		lib/my/my_printf.c \
		lib/my/part.c \
		lib/my/simple_flags.c \
		lib/my/concat_params.c \
		lib/my/my_find_prime_sup.c \
		lib/my/my_putnbr_base.c \
		lib/my/my_showmem.c \
		lib/my/my_strcat.c \
		lib/my/my_str_isalpha.c \
		lib/my/my_strlen.c \
		lib/my/my_strstr.c \
		lib/my/my_getnbr.c \
		lib/my/my_put_nbr.c \
		lib/my/my_showstr.c \
		lib/my/my_strcat_char.c \
		lib/my/my_str_islower.c \
		lib/my/my_strlowcase.c \
		lib/my/my_str_to_word_array.c \
		lib/my/my_isneg.c \
		lib/my/my_putstr.c \
		lib/my/my_show_word_array.c \
		lib/my/my_strcmp.c \
		lib/my/my_str_isnum.c \
		lib/my/my_strncat.c \
		lib/my/my_strupcase.c \
		lib/my/my_compute_power_rec.c \
		lib/my/my_is_prime.c \
		lib/my/my_put_unsigned.c \
		lib/my/my_sort_int_array.c \
		lib/my/my_strcpy.c \
		lib/my/my_str_isprintable.c \
		lib/my/my_strncmp.c \
		lib/my/my_swap.c \
		lib/my/my_compute_square_root.c \
		lib/my/my_putchar.c \
		lib/my/my_revstr.c  \
		lib/my/my_strcapitalize.c \
		lib/my/my_strdup.c \
		lib/my/my_str_isupper.c \
		lib/my/my_strncpy.c \
		lib/my/my_str_to_special_array.c \
		lib/my/new_word_array.c

SRC		= $(SRC_LIB) \
	    src/main.c \
        src/error.c \
        src/display.c \
        src/connect.c \
        src/gameloop.c \
        src/shoot.c \
        src/signal_handling.c \
        src/for_signal.c \
        src/cases.c

CFLAGS = -I include/

CFLAGS += -g -W -Wall -Wextra -Werror

TESTS	=	$(SRC)

OBJ	=	$(SRC:.c=.o)

OBJ_TESTS =	$(TESTS:.c=.o)

NAME	=	navy

RM	=	rm -f

TEST_NAME =	unit_tests

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ)

tests_run:	$(OBJ_TESTS)
		gcc $(CFLAGS) -o $(TEST_NAME) $(OBJ_TESTS) -lcriterion --coverage
		./unit_tests

tclean:
	$(RM) $(OBJ_TESTS) $(TEST_NAME)

clean:
	$(RM) $(OBJ)

fclean: clean tclean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
