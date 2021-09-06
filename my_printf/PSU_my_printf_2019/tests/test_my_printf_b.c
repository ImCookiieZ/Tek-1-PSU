/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_b_1, .init = redirect_all_std)
{
    my_printf("%b", 1);
    cr_assert_stdout_eq_str("1");
}

Test(my_printf, flag_b_12, .init = redirect_all_std)
{
    my_printf("%b", 12);
    cr_assert_stdout_eq_str("1100");
}

Test(my_printf, flag_b_max_int, .init = redirect_all_std)
{
    my_printf("%b", 2147483647);
    cr_assert_stdout_eq_str("1111111111111111111111111111111");
}

Test(my_printf, flag_b_max_u, .init = redirect_all_std)
{
    my_printf("%b", 4294967295);
    cr_assert_stdout_eq_str("11111111111111111111111111111111");
}