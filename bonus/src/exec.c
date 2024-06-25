/*
** EPITECH PROJECT, 2024
** stumper
** File description:
** stumper
*/

#include "../include/minicut.h"

int show_me(int current, linked_list_t *ref)
{
    for (linked_list_t *tmp = ref; ref != NULL; ref = ref->next) {
        if (current == *(int *)(ref->data))
            return 1;
        if (*(int *)(ref->data) == -1 && *(int *)(ref->prev->data) <= current)
            return 1;
    }
    return 0;
}

void exec_fields(minicut_t *minicut, char *line)
{
    char del[2] = {0};
    int start = 0;
    char **elt;

    del[0] = minicut->delimiter;
    if (my_strstr(line, del) == NULL) {
        my_putstr(line);
        return;
    }
    elt = STR2ARRAY_SEP(line, del);
    for (int index = 0; elt[index] != NULL; index++) {
        if (show_me(index + 1, minicut->fields) == 0)
            continue;
        if (start == 1)
            my_putchar(minicut->delimiter);
        my_putstr(elt[index]);
        start = 1;
    }
    my_free_array((void **)elt);
}

void exec_characters(minicut_t *minicut, char *line)
{
    for (int index = 0; line[index] != '\0'; index++) {
        if (show_me(index + 1, minicut->characters) == 0)
            continue;
        my_putchar(line[index]);
    }
}

int execute_minicut(minicut_t *minicut)
{
    for (int i = 0; minicut->lines[i] != NULL; i++) {
        if (minicut->fields != NULL) {
            exec_fields(minicut, minicut->lines[i]);
            my_putchar('\n');
            continue;
        }
        exec_characters(minicut, minicut->lines[i]);
        my_putchar('\n');
    }
    my_free_array((void **)minicut->lines);
    return 0;
}
