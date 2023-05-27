/*
** EPITECH PROJECT, 2023
** antman
** File description:
** key.c
*/

#include "antman.h"

int len_of_int(unsigned int nbr)
{
    int result = 0;

    while (nbr > 0) {
        result++;
        nbr /= 10;
    }
    return result;
}

void code_key(list_t *list, char **key)
{
    char *caractere;

    if (list && list->left && list->right) {
        code_key(list->left, key);
        code_key(list->right, key);
        return;
    }
    caractere = (char *)malloc(sizeof(char) * 3);
    caractere[0] = list->caractere;
    caractere[1] = (char)my_strlen(list->binary);
    caractere[2] = '\0';
    char *tmp = my_strcat(*key, caractere);
    free(caractere);
    free(*key);
    *key = my_strcat(tmp, list->binary);
    free(tmp);
}

int print_key(var_t *var)
{
    char *key = (char *)malloc(sizeof(char) * (var->lead_nb * 10));
    unsigned int len = 0;
    int len_of_len = 0;

    if (!key)
        return 84;
    for (unsigned i = 0; i < var->lead_nb * 10; i++)
        key[i] = '\0';
    code_key(var->list, &key);
    len = my_strlen(key);
    len_of_len = len_of_int(len);
    write(1, &len_of_len, 1);
    my_put_nbr(len, 0);
    write(1, key, len);
    free(key);
    return 0;
}
