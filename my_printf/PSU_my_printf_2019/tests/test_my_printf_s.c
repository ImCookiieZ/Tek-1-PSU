/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_s_hello, .init = redirect_all_std)
{
    my_printf("%s", "Hello_world");
    cr_assert_stdout_eq_str("Hello_world");
}

Test(my_printf, flag_s_number, .init = redirect_all_std)
{
    my_printf("%s", "12345678900987654321");
    cr_assert_stdout_eq_str("12345678900987654321");
}

Test(my_printf, flag_s_with_new_line_and_space, .init = redirect_all_std)
{
    my_printf("%s", "new line : \n");
    cr_assert_stdout_eq_str("new line : \n");
}

Test(my_printf, flag_s_null, .init = redirect_all_std)
{
    my_printf("%s", " \0");
    cr_assert_stdout_eq_str(" \0");
}