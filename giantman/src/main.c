/*
** EPITECH PROJECT, 2023
** antman
** File description:
** main.c
*/

#include "antman.h"

int handle_error2(int argc, char **argv)
{
    if (argc != 3)
        return 84;
    if (my_strcmp(argv[2], "1") != 0 && my_strcmp(argv[2], "2") != 0
    && my_strcmp(argv[2], "3") != 0)
        return 84;
    return 0;
}

char *read_file2(var_t *var, char *file)
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

char *get_binary(var_t *var, char *key, int max)
{
    int i = 0;
    char *binary = "";
    char *caractere = (char *)malloc(sizeof(char) * 2);

    caractere[1] = '\0';
    var->i += 1;
    for (; i < max; var->i += 1, i++) {
        caractere[0] = key[var->i];
        binary = my_strcat(binary, caractere);
    }
    free(caractere);
    return binary;
}

char *convert_to_binary(var_t *var, char *buf)
{
    char *octal = ""; int i = var->start;
    size_t len = var->size - (size_t)var->start + 1;
    char *result = (char *)malloc(sizeof(char) * len * 8);
    if (!result)
        return NULL;
    int k = 0;
    for (; buf[i + 2] != 't' || buf[i + 3] != 'i' || buf[i + 4] != 'c'
    || buf[i + 5] != '&' || buf[i + 6] != 't' || buf[i + 7] != 'a' ||
    buf[i + 8] != 'c'; i++) {
        for (int j = 7; j >= 0; j--) {
            int c = buf[i];
            int b = 1 << j;
            result[k] = c & b ? '1' : '0';
            k++;
        }
    } result[k] = '\0';
    octal = my_putnbr_base2((unsigned char)buf[i], 2, buf[i + 1] - 48);
    result = my_strcat(result, octal);
    free(octal);
    return result;
}

int main(int argc, char **argv)
{
    var_t *var = (var_t *)malloc(sizeof(var_t));
    char *buf = read_file2(var, argv[1]);
    int ret = 0; var->list = NULL;
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return help2();
    if (!buf || !var || handle_error2(argc, argv) == 84) {
        ret = 84;
    } else if (var->size <= 1) {
        write(1, buf, my_strlen(buf));
        ret = 0;
    } else {
        if (create_linked_list(var, buf) == 84) {
            ret = 84;
        } else {
            char *binary = convert_to_binary(var, buf);
            ret = binary ? 0 : 84;
            get_caracteres(var, binary);
        }
    }
    return free_resources2(buf, var, ret);
}
