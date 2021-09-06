/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_hash0x_1, .init = redirect_all_std)
{
    my_printf("%#0x", 1);
    cr_assert_stdout_eq_str("0x1");
}

Test(my_printf, flag_hash08x_12, .init = redirect_all_std)
{
    my_printf("%#08x", 12);
    cr_assert_stdout_eq_str("0x00000c");
}

Test(my_printf, flag_hashx_max, .init = redirect_all_std)
{
    my_printf("%#x", 4294967295);
    cr_assert_stdout_eq_str("0xffffffff");
}

Test(my_printf, flag_hashx_intmax, .init = redirect_all_std)
{
    my_printf("%#x", 2147483647);
    cr_assert_stdout_eq_str("0x7fffffff");
}

Test(my_printf, flag_hash8x_23, .init = redirect_all_std)
{
    my_printf("%#8x", 23);
    cr_assert_stdout_eq_str("    0x17");
}