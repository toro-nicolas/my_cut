/*
** EPITECH PROJECT, 2024
** my_cut
** File description:
** The main file of the my_cut project
*/

#include "../include/minicut.h"

static int *get_nb(char *nb)
{
    int *new_int = MALLOC(4);

    if (nb == NULL)
        return NULL;
    new_int[0] = my_super_number(nb, (NB){0, 0, 0, 0});
    if (my_errno != 0)
        return NULL;
    return new_int;
}

static int add_multi(linked_list_t **list, char **line)
{
    int *nb = get_nb(line[0]);
    int *nb2 = get_nb(line[1]);
    int *nb4;

    if (nb == NULL)
        return 1;
    my_push_back(list, nb, INT);
    if (my_array_len((void **)line) == 1) {
        my_push_back(list, get_nb("-1"), INT);
        return 0;
    }
    if (nb2 == NULL || *nb > *nb2)
        return 1;
    for (int nb3 = *nb + 1; nb3 < *nb2; nb3++) {
        nb4 = MALLOC(4);
        nb4[0] = nb3;
        my_push_back(list, nb4, INT);
    }
    my_push_back(list, nb2, INT);
    return 0;
}

linked_list_t *get_nb_list(char *str)
{
    linked_list_t *list = NULL;
    char **line = STR2ARRAY_SEP(str, ",");
    char **multi_nb = NULL;
    int *nb;

    for (int index = 0; line[index] != NULL; index++) {
        nb = get_nb(line[index]);
        if (my_strstr(line[index], "-") == NULL && nb == NULL)
            return NULL;
        if (my_strstr(line[index], "-") == NULL && nb != NULL) {
            my_push_back(&list, nb, INT);
            continue;
        }
        multi_nb = STR2ARRAY_SEP(line[index], "-");
        if (add_multi(&list, multi_nb))
            return NULL;
    }
    my_free_array((void **)multi_nb);
    my_free_array((void **)line);
    return list;
}

static int check_delimiter(minicut_t *minicut, char *flag, char *option)
{
    if (flag[1] == 'd' && my_strlen(flag) == 3) {
        minicut->delimiter = flag[2];
        return 1;
    }
    if (flag[1] == 'd' && flag[2] == '\0' &&
    option != NULL && my_strlen(option) == 1) {
        minicut->delimiter = option[0];
        return 2;
    }
    if (my_strcmp(flag, "--delimiter") == 0 &&
    option != NULL && my_strlen(option) == 1) {
        minicut->delimiter = option[0];
        return 2;
    }
    return 0;
}

static int check_characters(minicut_t *minicut, char *flag, char *option)
{
    if (flag[1] == 'c' && my_strlen(flag) > 2) {
        minicut->characters = get_nb_list(flag + 2);
        if (minicut->characters != NULL)
            return 1;
        return 0;
    }
    if (flag[1] == 'c' && flag[2] == '\0' && option != NULL) {
        minicut->characters = get_nb_list(option);
        if (minicut->characters != NULL)
            return 2;
        return 0;
    }
    if (my_strcmp(flag, "--characters") == 0 && option != NULL) {
        minicut->characters = get_nb_list(option);
        if (minicut->characters != NULL)
            return 2;
    }
    return 0;
}

static int check_fields(minicut_t *minicut, char *flag, char *option)
{
    if (flag[1] == 'f' && my_strlen(flag) > 2) {
        minicut->fields = get_nb_list(flag + 2);
        if (minicut->fields != NULL)
            return 1;
        return 0;
    }
    if (flag[1] == 'f' && flag[2] == '\0' && option != NULL) {
        minicut->fields = get_nb_list(option);
        if (minicut->fields != NULL)
            return 2;
        return 0;
    }
    if (my_strcmp(flag, "--fields") == 0 && option != NULL) {
        minicut->fields = get_nb_list(option);
        if (minicut->fields != NULL)
            return 2;
    }
    return 0;
}

int check_options(minicut_t *minicut, char *flag, char *option)
{
    int result = 0;

    result = check_characters(minicut, flag, option);
    if (result != 0)
        return result;
    result = check_delimiter(minicut, flag, option);
    if (result != 0)
        return result;
    result = check_fields(minicut, flag, option);
    if (result != 0)
        return result;
    return 0;
}

minicut_t *create_minicut(char *content)
{
    minicut_t *minicut = MALLOC(sizeof(minicut_t));

    minicut->characters = NULL;
    minicut->delimiter = '\t';
    minicut->fields = NULL;
    minicut->lines = STR2ARRAY_SEP(content, "\n");
    return minicut;
}

int init_minicut(int argc, char **argv, char *content)
{
    minicut_t *minicut = create_minicut(content);
    int valid = 0;

    for (int index = 1; index < argc; index++) {
        if (argv[index][0] != '-')
            return my_putstr_error("Flag are invalid\n");
        valid = check_options(minicut, argv[index], argv[index + 1]);
        if (valid == 2) {
            index = index + 1;
            continue;
        }
        if (valid) {
            continue;
        } else
            return my_putstr_error("Options are invalid\n");
    }
    if ((minicut->characters == NULL && minicut->fields == NULL)
    || (minicut->characters != NULL && minicut->fields != NULL))
        return my_putstr_error("Error with characters or fields\n");
    return execute_minicut(minicut);
}
