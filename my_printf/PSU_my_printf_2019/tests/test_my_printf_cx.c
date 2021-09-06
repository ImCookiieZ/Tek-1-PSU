/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_cx_1, .init = redirect_all_std)
{
    my_printf("%X", 1);
    cr_assert_stdout_eq_str("1");
}

Test(my_printf, flag_cx_12, .init = redirect_all_std)
{
    my_printf("%X", 12);
    cr_assert_stdout_eq_str("C");
}

Test(my_printf, flag_cx_max_int, .init = redirect_all_std)
{
    my_printf("%X", 2147483647);
    cr_assert_stdout_eq_str("7FFFFFFF");
}

Test(my_printf, flag_cx_max_u, .init = redirect_all_std)
{
    my_printf("%X", 4294967295);
    cr_assert_stdout_eq_str("FFFFFFFF");
}