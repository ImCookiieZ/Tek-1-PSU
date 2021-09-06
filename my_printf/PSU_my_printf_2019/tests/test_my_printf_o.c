/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_o_1, .init = redirect_all_std)
{
    my_printf("%o", 1);
    cr_assert_stdout_eq_str("1");
}

Test(my_printf, flag_o_12, .init = redirect_all_std)
{
    my_printf("%o", 12);
    cr_assert_stdout_eq_str("14");
}

Test(my_printf, flag_o_max_int, .init = redirect_all_std)
{
    my_printf("%o", 2147483647);
    cr_assert_stdout_eq_str("17777777777");
}

Test(my_printf, flag_o_max_u, .init = redirect_all_std)
{
    my_printf("%o", 4294967295);
    cr_assert_stdout_eq_str("37777777777");
}