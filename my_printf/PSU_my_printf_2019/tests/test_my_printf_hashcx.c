/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_hash0cx_1, .init = redirect_all_std)
{
    my_printf("%#0X", 1);
    cr_assert_stdout_eq_str("0x1");
}

Test(my_printf, flag_hash08cx_12, .init = redirect_all_std)
{
    my_printf("%#08X", 12);
    cr_assert_stdout_eq_str("0x00000C");
}

Test(my_printf, flag_hashcx_max, .init = redirect_all_std)
{
    my_printf("%#X", 4294967295);
    cr_assert_stdout_eq_str("0xFFFFFFFF");
}

Test(my_printf, flag_hashcx_intmax, .init = redirect_all_std)
{
    my_printf("%#X", 2147483647);
    cr_assert_stdout_eq_str("0x7FFFFFFF");
}

Test(my_printf, flag_hash8cx_23, .init = redirect_all_std)
{
    my_printf("%#8X", 23);
    cr_assert_stdout_eq_str("    0x17");
}