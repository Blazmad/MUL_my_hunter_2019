/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** game.c
*/

#include "my.h"

void game_clock(sfRenderWindow *window, game_t *game, score_t *score)
{
    game->time = sfClock_getElapsedTime(game->clocks);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds >= 0.1) {
        sfClock_restart(game->clocks);
        display_hitler(game, score);
        display_score(score);
    }
    draw_life(window, game, score);
    draw_sprite(window, game, score);
}

int menu(game_t game, score_t score)
{
	sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Heil Hunter !",
        sfResize | sfClose, NULL);
    sfEvent event;

    sfRenderWindow_setFramerateLimit(window, 30);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window, event, &game, &score);
        game_clock(window, &game, &score);
        if (score.loose == 3) {
            my_printf("\n\tYOU LOST !! Hitler Won, try again !");
            my_printf("\n\n\tYour Score : %s\n\n", score.res);
            return (1);
        }
    }
    destroy_all(window, game, score);
    return (0);
}

void destroy_all(sfRenderWindow *window, game_t game, score_t score)
{
    sfSprite_destroy(game.s_hitler);
    sfTexture_destroy(game.t_hitler);
    sfSprite_destroy(game.s_background);
    sfTexture_destroy(game.t_background);
    sfSprite_destroy(game.s_sniper);
    sfTexture_destroy(game.t_sniper);
    sfClock_destroy(game.clocks);
    sfText_destroy(score.text);
    sfText_destroy(score.score);
    sfFont_destroy(score.font);
    sfSprite_destroy(game.s_star_3);
    sfSprite_destroy(game.s_star_2);
    sfSprite_destroy(game.s_star_1);
    sfTexture_destroy(game.t_star);
    sfRenderWindow_destroy(window);
}