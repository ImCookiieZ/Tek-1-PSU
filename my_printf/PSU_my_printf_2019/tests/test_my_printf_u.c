/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_u_1, .init = redirect_all_std)
{
    my_printf("%u", 1);
    cr_assert_stdout_eq_str("1");
}

Test(my_printf, flag_u_12, .init = redirect_all_std)
{
    my_printf("%u", 12);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, flag_u_int_max, .init = redirect_all_std)
{
    my_printf("%u", 2147483647);
    cr_assert_stdout_eq_str("2147483647");
}

Test(my_printf, flag_u_max, .init = redirect_all_std)
{
    my_printf("%u", 4294967295);
    cr_assert_stdout_eq_str("4294967295");
}