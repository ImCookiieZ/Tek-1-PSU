/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, flag_hash0o_1, .init = redirect_all_std)
{
    my_printf("%#0o", 1);
    cr_assert_stdout_eq_str("01");
}

Test(my_printf, flag_hash08o_12, .init = redirect_all_std)
{
    my_printf("%#08o", 12);
    cr_assert_stdout_eq_str("00000014");
}

Test(my_printf, flag_hasho_max, .init = redirect_all_std)
{
    my_printf("%#o", 4294967295);
    cr_assert_stdout_eq_str("037777777777");
}

Test(my_printf, flag_hasho_intmax, .init = redirect_all_std)
{
    my_printf("%#o", 2147483647);
    cr_assert_stdout_eq_str("017777777777");
}

Test(my_printf, flag_hash8o_23, .init = redirect_all_std)
{
    my_printf("%#8o", 23);
    cr_assert_stdout_eq_str("     027");
}