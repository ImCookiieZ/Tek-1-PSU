/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_cs_hello, .init = redirect_all_std)
{
    my_printf("%S", "Hello_world");
    cr_assert_stdout_eq_str("Hello_world");
}

Test(my_printf, flag_cs_one_nonprintable , .init = redirect_all_std)
{
    char *a = my_strdup("hallo");
    a[0] = 2;
    my_printf("%S", a);
    cr_assert_stdout_eq_str("\\002allo");
}

Test(my_printf, flag_cs_more_nonprintable, .init = redirect_all_std)
{
    char a[4] = {2, 22, 9, 13};
    my_printf("%S", a);
    cr_assert_stdout_eq_str("\\002\\026\\011\\015");
}

Test(my_printf, flag_cs_over_127, .init = redirect_all_std)
{
    char a[4] = {2, 133, 255, 0};
    my_printf("%S", a);
    cr_assert_stdout_eq_str("\\002\\205\\377");
}