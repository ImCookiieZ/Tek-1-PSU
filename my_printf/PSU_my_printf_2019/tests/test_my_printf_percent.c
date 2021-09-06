/*
** EPITECH PROJECT, 2019
** s
** File description:
** s
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_percent_only, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, flag_percent_three, .init = redirect_all_std)
{
    my_printf("%%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, flag_percent_double, .init = redirect_all_std)
{
    my_printf("%%%%");
    cr_assert_stdout_eq_str("%%");
}

Test(my_printf, flag_percent_double_between, .init = redirect_all_std)
{
    my_printf("%%hallo%%");
    cr_assert_stdout_eq_str("%hallo%");
}