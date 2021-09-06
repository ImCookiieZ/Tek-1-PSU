/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_c_h, .init = redirect_all_std)
{
    my_printf("%c", 'h');
    cr_assert_stdout_eq_str("h");
}

Test(my_printf, flag_c_number, .init = redirect_all_std)
{
    my_printf("%c", '1');
    cr_assert_stdout_eq_str("1");
}

Test(my_printf, flag_c_with_new_line, .init = redirect_all_std)
{
    my_printf("%c", '\n');
    cr_assert_stdout_eq_str("\n");
}

Test(my_printf, flag_c_space, .init = redirect_all_std)
{
    my_printf("%c", ' ');
    cr_assert_stdout_eq_str(" ");
}