/*
** EPITECH PROJECT, 2023
** antman
** File description:
** help.c
*/

#include "antman.h"

int help2(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./giantman [path_to_file_containing_compressed_data]");
    my_putstr("[number (file_type)]\n\n");
    my_putstr("\tfile type number : \n");
    my_putstr("\t1 : Lyrics (.lyr)\n");
    my_putstr("\t2 : Web page (.HTML)\n");
    my_putstr("\t3 : Images (.PPM)\n\n");
    my_putstr("DETAILS\n");
    my_putstr("\tour program will then print");
    my_putstr(" the readable file \n\tthe compressed data was");
    my_putstr(" based of on the standard output\n\n");
    my_putstr("Created by Theo_EwzZer and TheoMars16\n");
    return 0;
}
