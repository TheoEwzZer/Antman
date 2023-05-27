/*
** EPITECH PROJECT, 2023
** antman
** File description:
** main.c
*/

#include "antman.h"

int print_ascii(var_t *var, char *str, size_t len)
{
    unsigned char *bin = (unsigned char *)malloc(sizeof(unsigned char) * len);
    int j = 0, k = 0; unsigned char c = 0;
    if (!bin)
        return 84;
    for (unsigned int i = 0; i < len; i++) {
        c += str[i] - '0';
        j++;
        if (j == 8 || i + 1 == len) {
            bin[k++] = c;
            c = 0, j = 0;
        } else
            c <<= 1;
    } if (j != 0)
        bin[k++] = c << (8 - j);
    write(1, bin, (size_t)k);
    my_put_nbr(len % 8, 0);
    write(1, "tic&tac", 7);
    write(1, &var->type, 1);
    free(bin);
    return 0;
}

char *read_file(var_t *var, char *file)
{
    struct stat sb;
    char *buf;
    int fd = 0;

    if (stat(file, &sb) != 0)
        return NULL;
    var->size = (size_t)(sb.st_size);
    buf = (char *)malloc(sizeof(char) * (var->size + 1));
    if (!buf)
        return NULL;
    buf[var->size] = '\0';
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return NULL;
    if (read(fd, buf, var->size) < 0)
        return NULL;
    close(fd);
    return buf;
}

int handle_error(int argc, char **argv)
{
    if (argc != 3)
        return 84;
    if (my_strcmp(argv[2], "1") != 0 && my_strcmp(argv[2], "2") != 0
    && my_strcmp(argv[2], "3") != 0)
        return 84;
    return 0;
}

void free_resources(char *buf, var_t *var)
{
    free(buf);
    while (var->list) {
        list_t *tmp = var->list;
        var->list = var->list->next;
        free(tmp);
    }
    free(var->list);
    free(var->seen);
    free(var);
}

int main(int argc, char **argv)
{
    var_t *var = (var_t *)malloc(sizeof(var_t));
    char *buf = read_file(var, argv[1]);
    var->list = NULL;
    var->seen = NULL;
    int ret = 0;
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return help();
    if (!buf || !var || handle_error(argc, argv) == 84) {
        ret = 84;
    } else if (var->size <= 1) {
        write(1, buf, my_strlen(buf));
        ret = 0;
    } else {
        var->type = argv[2][0];
        ret = following(var, buf);
    }
    free_resources(buf, var);
    return ret;
}
