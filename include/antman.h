/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

#ifndef ANTMAN_H_

    #define ANTMAN_H_

    #include "my.h"
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>

typedef struct list {
    char *binary;
    char caractere;
    int occ;
    int valide;
    struct list *daddy;
    struct list *left;
    struct list *next;
    struct list *right;
} list_t;

typedef struct var {
    char *key;
    int *seen;
    int i;
    int start;
    char type;
    list_t *list;
    list_t *ptr;
    size_t size;
    unsigned int lead_nb;
} var_t;

char *add_zero(char *str, int len, int j);
void code_key(list_t *list, char **key);
char *convert_to_binary(var_t *var, char *buf);
char *get_binary(var_t *var, char *key, int max);
char *my_putnbr_base2(int nbr, int base, int j);
char *read_file(var_t *var, char *file);
char *read_file2(var_t *var, char *file);
char *search_char(list_t *list, char c);
int check_binary(char *str, list_t *list);
int check_push(int *occ, var_t *var, unsigned int i);
int create_linked_list(var_t *var, char *buf);
int create_list(char *buf, var_t *var);
int create_tree(var_t *var);
int following(var_t *var, char *buf);
int handle_error(int argc, char **argv);
int handle_error2(int argc, char **argv);
int len_of_int(unsigned int nbr);
int print_ascii(var_t *var, char *str, size_t len);
int print_key(var_t *var);
int push(char caractere, int occ, var_t *var);
int push2(char caractere, char *binary, var_t *var);
int put_in_tree(var_t *var, list_t *left, list_t *right);
int replace_with_bin(char *buf, var_t *var);
list_t *get_min_node(var_t *var);
list_t *get_node(var_t *var, char *str);
void free_resources(char *buf, var_t *var);
int free_resources2(char *buf, var_t *var, int ret);
void get_caracteres(var_t *var, char *str);
int help(void);
int help2(void);
void setup_bin(list_t *list, char *binary);

#endif /* ANTMAN_H_ */
