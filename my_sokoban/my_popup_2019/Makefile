##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## for evalexpr
##

SRC_LIB		=lib/my/concat_params.c \
		lib/my/my_strcat_char.c \
		lib/my/my_compute_power_rec.c \
		lib/my/my_strcmp.c \
		lib/my/my_compute_square_root.c \
		lib/my/my_strcpy.c \
		lib/my/my_delete_zeros.c \
		lib/my/my_strdup.c \
		lib/my/my_find_prime_sup.c \
		lib/my/my_str_isalpha.c \
		lib/my/my_getnbr.c \
		lib/my/my_str_islower.c \
		lib/my/my_isneg.c \
		lib/my/my_str_isnum.c \
		lib/my/my_is_prime.c \
		lib/my/my_str_isprintable.c \
		lib/my/my_putchar.c \
		lib/my/my_str_isupper.c \
		lib/my/my_put_nbr.c \
		lib/my/my_strlen.c \
		lib/my/my_putstr.c \
		lib/my/my_strlowcase.c \
		lib/my/my_revstr.c \
		lib/my/my_strncat.c \
		lib/my/my_showmem.c \
		lib/my/my_strncmp.c \
		lib/my/my_showstr.c \
		lib/my/my_strncpy.c \
		lib/my/my_show_word_array.c \
		lib/my/my_strstr.c \
		lib/my/my_sort_int_array.c \
		lib/my/my_str_to_word_array.c \
		lib/my/my_strcapitalize.c \
		lib/my/my_strupcase.c \
		lib/my/my_strcat.c \
		lib/my/my_swap.c

SRC		= $(SRC_LIB) \
		main.c

OBJ		=	$(SRC:.c=.o)

NAME		=	my_popup

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ) $(OBJ_TEST) $(OBJ_MAIN)

fclean: clean
	rm -f $(NAME) $(MAIN) $(TEST)

re:	fclean all

.PHONY: all clean fclean re
