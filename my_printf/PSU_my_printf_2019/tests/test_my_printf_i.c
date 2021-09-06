/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_i_1, .init = redirect_all_std)
{
    my_printf("%i", 1);
    cr_assert_stdout_eq_str("1");
}

Test(my_printf, flag_i_12, .init = redirect_all_std)
{
    my_printf("%i", 12);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, flag_i_max, .init = redirect_all_std)
{
    my_printf("%i", 2147483647);
    cr_assert_stdout_eq_str("2147483647");
}

Test(my_printf, flag_i_min, .init = redirect_all_std)
{
    my_printf("%i", -2147483647);
    cr_assert_stdout_eq_str("-2147483647");
}

Test(my_printf, flag_i_mizero, .init = redirect_all_std)
{
    my_printf("%i", -0);
    cr_assert_stdout_eq_str("0");
}