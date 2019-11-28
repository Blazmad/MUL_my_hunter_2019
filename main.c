/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** main.c
*/

#include "my.h"

// void clocks_hitler(game_t game)
// {
//     game.time = sfClock_getElapsedTime(game.clocks);
//     game.seconds = game.time.microseconds / 1000000.0;
//     if (game.seconds >= 0.1) {
//         sfClock_restart(game.clocks);
//         display_hitler(&game);
//     }
// }
        // clocks_hitler(hitler);

void destroy_all(sfRenderWindow *window, game_t game)
{
    sfSprite_destroy(game.s_hitler);
    sfTexture_destroy(game.t_hitler);
    sfRenderWindow_destroy(window);
}

void draw_sprite(sfRenderWindow *window, game_t *game, score_t *score)
{
    sfRenderWindow_drawSprite(window, game->s_background, NULL);
    sfRenderWindow_drawSprite(window, game->s_hitler, NULL);
    sfSprite_setPosition(game->s_sniper, game->mouse);
    sfRenderWindow_drawSprite(window, game->s_sniper, NULL);
    sfRenderWindow_drawText(window, score->text, NULL);
    sfRenderWindow_drawText(window, score->score, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

int menu(game_t game, score_t score)
{
	sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "window", sfResize |
        sfClose, NULL);
    sfEvent event;

    sfRenderWindow_setFramerateLimit(window, 30);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window, event, &game, &score);
        game.time = sfClock_getElapsedTime(game.clocks);
        game.seconds = game.time.microseconds / 1000000.0;
        if (game.seconds >= 0.1) {
            sfClock_restart(game.clocks);
            display_hitler(&game);
            display_score(score);
        }
        draw_sprite(window, &game, &score);
    }
    destroy_all(window, game);
    return (0);
}

int main(void)
{
    game_t game;
    score_t score;

    game = get_hitler(game);
    score = get_text(score);

    menu(game, score);
	return (0);
}