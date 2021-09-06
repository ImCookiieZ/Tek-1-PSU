/*
** EPITECH PROJECT, 2019
** tests
** File description:
** for strings
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/struct.h"

Test(my_printf, mixed_flags1, .init = redirect_all_std)
{
    my_printf("nb1: %d, char of nb1: %c", 97, 97);
    cr_assert_stdout_eq_str("nb1: 97, char of nb1: a");
}

Test(my_printf, all_converting , .init = redirect_all_std)
{
    my_printf("unsigned: %u, \nbin: %b, \noct: %o, \nhexCap: %X, \
\nhexlow: %x\n", 4194934582, 4194934582, 4194934582, 4194934582, 4194934582);
    cr_assert_stdout_eq_str("unsigned: 4194934582, \nbin: \
11111010000010011001111100110110, \noct: 37202317466, \nhexCap: \
FA099F36, \nhexlow: fa099f36\n");
}

Test(my_printf, too_many_arguments, .init = redirect_all_std)
{
    my_printf("no argument", "huhu", 123, 'c');
    cr_assert_stdout_eq_str("no argument");
}
/*
Test(my_printf, not_enoght_arguments, .init = redirect_all_std)
{
    my_printf("%s%d", "hello");
    cr_assert_stdout_eq_str("hello");
    }*/
Test(my_printf, not_existing_flag, .init = redirect_all_std)
{
    my_printf("no ar%lgument", "huhu", 123, 'c');
    cr_assert_stdout_eq_str("no ar%lgument");
}
