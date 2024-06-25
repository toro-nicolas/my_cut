/*
** EPITECH PROJECT, 2024
** test_mymemory_lib
** File description:
** Unit tests for each function of the mymemory lib
*/
/**
 * @file test_mymemory_lib.c
 * @brief Unit tests for each function of the mymemory lib
 * @author Nicolas TORO
 */

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/mymemory.h"

Test(my_memset, test_my_memset)
{
    char *str = malloc(sizeof(char) * 10);

    cr_assert_not_null(str);
    my_memset(str, 'a', 10);
    cr_assert_str_eq(str, "aaaaaaaaaa");
    free(str);
}
