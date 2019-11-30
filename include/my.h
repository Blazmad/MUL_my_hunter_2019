/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** all prototypes
*/

#ifndef MY_H_
#define MY_H_

#include "hunter.h"
#include <stdarg.h>

void my_putchar(char);
int my_put_nbr(int);
int my_strlen(char const *);
int my_putstr(char const *);
int my_getnbr(char const *);
int my_get_nb(char c);
void exam_flags_one(char *str, int i, va_list ap);
void exam_flag_characters(char *str, int i, va_list ap);
int my_put_uns_nbr(int nbr);
int my_get_nbr_base(int nb, char *base);
int my_get_nbr_base_printable(char const *str);
int my_get_nbr_base_pointer(int nb, char *base);
int my_printf(char *str, ...);

#endif