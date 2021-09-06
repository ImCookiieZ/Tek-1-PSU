/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_sp_hello, .init = redirect_all_std)
{
    my_printf("%s%", "Hello_world");
    cr_assert_stdout_eq_str("Hello_world");
}

Test(my_printf, flag_ash_number, .init = redirect_all_std)
{
    my_printf("%a%s%h", "12345678900987654321");
    cr_assert_stdout_eq_str("%a12345678900987654321%h");
}

Test(my_printf, flag_pts_with_new_line_and_space, .init = redirect_all_std)
{
    my_printf("%ts", "new line : \n");
    cr_assert_stdout_eq_str("%ts");
}

Test(my_printf, flag_ps_null, .init = redirect_all_std)
{
    my_printf("%r%s", " \0");
    cr_assert_stdout_eq_str("%r ");
}