/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_09d_1, .init = redirect_all_std)
{
    my_printf("%09d", 1);
    cr_assert_stdout_eq_str("000000001");
}

Test(my_printf, flag_02d_12, .init = redirect_all_std)
{
    my_printf("%d", 12);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, flag_012d_max, .init = redirect_all_std)
{
    my_printf("%012d", 2147483647);
    cr_assert_stdout_eq_str("002147483647");
}

Test(my_printf, flag_0m12d_min, .init = redirect_all_std)
{
    my_printf("%0-12d", -2147483647);
    cr_assert_stdout_eq_str("-2147483647 ");
}

Test(my_printf, flag_0m8d_spaces_mizero, .init = redirect_all_std)
{
    my_printf("%0-8d", -0);
    cr_assert_stdout_eq_str("0       ");
}