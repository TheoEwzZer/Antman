/*
** EPITECH PROJECT, 2023
** antman
** File description:
** tree.c
*/

#include "antman.h"

int put_in_tree(var_t *var, list_t *left, list_t *right)
{
    list_t *node = (list_t *)malloc(sizeof(list_t));

    if (!node)
        return 84;
    node->caractere = 42;
    node->occ = left->occ + right->occ;
    node->left = left;
    node->right = right;
    node->daddy = NULL;
    node->valide = 1;
    left->daddy = node;
    right->daddy = node;
    node->next = var->list;
    var->list = node;
    return 0;
}

list_t *get_min_node(var_t *var)
{
    list_t *min = var->list;
    list_t *tmp = NULL;

    while (min && !min->valide)
        min = min->next;
    tmp = min->next;
    while (tmp) {
        if (tmp->occ < min->occ && tmp->valide)
            min = tmp;
        tmp = tmp->next;
    }
    min->valide = 0;
    return min;
}

int create_tree(var_t *var)
{
    list_t *left = var->list;
    list_t *right = NULL;

    if (!left)
        return 84;
    for (unsigned int i = 0; i < (var->lead_nb - 1); i++) {
        left = get_min_node(var);
        right = get_min_node(var);
        if (put_in_tree(var, left, right) == 84)
            return 84;
    }
    return 0;
}
