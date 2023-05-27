/*
** EPITECH PROJECT, 2023
** antman
** File description:
** help.c
*/

#include "antman.h"

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./antman [path_to_file_we_want_to_compressed]");
    my_putstr("[number (file_type)]\n\n");
    my_putstr("\tfile type number : \n");
    my_putstr("\t1 : Lyrics (.lyr)\n");
    my_putstr("\t2 : Web page (.HTML)\n");
    my_putstr("\t3 : Images (.PPM)\n\n");
    my_putstr("DETAILS\n");
    my_putstr("\tour program will then print");
    my_putstr(" a compressed version of the file on the standard output\n");
    my_putstr("\tIt should be possibleto redirect ");
    my_putstr("the compressed data to a file.\n\n");
    my_putstr("Created by Theo_EwzZer  and TheoMars16\n");
    return 0;
}
