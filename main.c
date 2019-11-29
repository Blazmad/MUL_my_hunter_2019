/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    game_t game;
    score_t score;

    if (ac == 2) {
        if (av[1][0] == '-' &&av[1][1] == 'h' && av[1][2] == '\0') {
            my_putstr("HELP");
            return (0);
        }
    }
    game = get_hitler(game);
    game = get_star(game);
    score = get_text(score);
    menu(game, score);
	return (0);
}