/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_x_1, .init = redirect_all_std)
{
    my_printf("%x", 1);
    cr_assert_stdout_eq_str("1");
}

Test(my_printf, flag_x_12, .init = redirect_all_std)
{
    my_printf("%x", 12);
    cr_assert_stdout_eq_str("c");
}

Test(my_printf, flag_x_max_int, .init = redirect_all_std)
{
    my_printf("%x", 2147483647);
    cr_assert_stdout_eq_str("7fffffff");
}

Test(my_printf, flag_x_max_u, .init = redirect_all_std)
{
    my_printf("%x", 4294967295);
    cr_assert_stdout_eq_str("ffffffff");
}