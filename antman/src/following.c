/*
** EPITECH PROJECT, 2023
** following
** File description:
** following
*/

#include "antman.h"

int following(var_t *var, char *buf)
{
    var->lead_nb = 0;
    var->ptr = var->list;
    if (create_list(buf, var) == 84)
        return 84;
    if (create_tree(var) == 84)
        return 84;
    var->ptr = var->list;
    setup_bin(var->list, "");
    var->list = var->ptr;
    if (print_key(var) == 84)
        return 84;
    replace_with_bin(buf, var);
    return 0;
}
