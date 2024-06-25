/*
** EPITECH PROJECT, 2024
** stumper
** File description:
** stumper
*/

#include "mymemory.h"

#ifndef MINICUT_H_
    #define MINICUT_H_

typedef struct minicut_s {
    linked_list_t *characters;
    char delimiter;
    linked_list_t *fields;
    char **lines;
} minicut_t;

int init_minicut(int argc, char **argv, char *content);
int execute_minicut(minicut_t *minicut);

#endif /* MINICUT_H_ */
