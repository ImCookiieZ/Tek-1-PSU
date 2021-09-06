/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_hash0p_1, .init = redirect_all_std)
{
    my_printf("%#0p", 1);
    cr_assert_stdout_eq_str("0x1");
}

Test(my_printf, flag_hash08p_12, .init = redirect_all_std)
{
    my_printf("%#08p", 12);
    cr_assert_stdout_eq_str("0x00000c");
}

Test(my_printf, flag_hashp_max, .init = redirect_all_std)
{
    my_printf("%#p", 4294967295);
    cr_assert_stdout_eq_str("0xffffffff");
}

Test(my_printf, flag_hashp_intmax, .init = redirect_all_std)
{
    my_printf("%#p", 2147483647);
    cr_assert_stdout_eq_str("0x7fffffff");
}

Test(my_printf, flag_hash8p_23, .init = redirect_all_std)
{
    my_printf("%#8p", 23);
    cr_assert_stdout_eq_str("    0x17");
}