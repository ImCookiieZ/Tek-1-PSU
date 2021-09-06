/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_d_1, .init = redirect_all_std)
{
    my_printf("%d", 1);
    cr_assert_stdout_eq_str("1");
}

Test(my_printf, flag_d_12, .init = redirect_all_std)
{
    my_printf("%d", 12);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, flag_d_max, .init = redirect_all_std)
{
    my_printf("%d", 2147483647);
    cr_assert_stdout_eq_str("2147483647");
}

Test(my_printf, flag_d_min, .init = redirect_all_std)
{
    my_printf("%d", -2147483647);
    cr_assert_stdout_eq_str("-2147483647");
}

Test(my_printf, flag_d_mizero, .init = redirect_all_std)
{
    my_printf("%d", -0);
    cr_assert_stdout_eq_str("0");
}