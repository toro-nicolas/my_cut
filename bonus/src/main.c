/*
** EPITECH PROJECT, 2023
** stumper3
** File description:
** The main file of the project
*/
/**
 * @file main.c
 * @brief The main file of the project
 * @author Nicolas TORO and Raphael ROSSIGNOL
 */

#include "../include/minicut.h"

int main(int argc, char **argv)
{
    char readed_content[1000000];
    size_t size = 1000000;
    char *file_content = NULL;
    int result = 0;

    if (argc < 2)
        return my_putstr_error("No arguments passed\n");
    my_memset(readed_content, 0, 1000000);
    size = read(0, readed_content, size);
    file_content = my_strndup(readed_content, size);
    result = init_minicut(argc, argv, file_content);
    my_free();
    free(file_content);
    return result;
}
