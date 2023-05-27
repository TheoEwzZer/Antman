/*
** EPITECH PROJECT, 2023
** antman
** File description:
** list.c
*/

#include "antman.h"

int check_push(int *occ, var_t *var, unsigned int i)
{
    if (occ[i] > 0 && !var->seen[i]) {
        if (push((char)i, occ[i], var) == 84)
            return 84;
        var->seen[i] = 1;
    }
    return 0;
}

int create_list(char *buf, var_t *var)
{
    int *occ = (int *)malloc(sizeof(int) * 256);

    var->seen = (int *)malloc(sizeof(int) * 256);
    if (!occ || !var->seen)
        return 84;
    for (unsigned int i = 0; i < 256; i++) {
        occ[i] = 0;
        var->seen[i] = 0;
    }
    for (unsigned int i = 0; buf[i]; i++)
        occ[(unsigned char)buf[i]]++;
    for (unsigned int i = 0; i < 256; i++) {
        if (check_push(occ, var, i) == 84)
            return 84;
    }
    free(occ);
    return 0;
}

int push(char caractere, int occ, var_t *var)
{
    list_t *leaf = (list_t *)malloc(sizeof(list_t));
    list_t *last = var->list;
    if (!leaf)
        return 84;
    if (var->seen[(unsigned char)caractere])
        return 0;
    var->lead_nb += 1;
    leaf->caractere = caractere;
    leaf->occ = occ, leaf->next = NULL;
    leaf->daddy = NULL, leaf->left = NULL;
    leaf->right = NULL;
    leaf->valide = 1;
    if (!var->list) {
        var->list = leaf;
        return 0;
    }
    while (last->next)
        last = last->next;
    last->next = leaf;
    return 0;
}
