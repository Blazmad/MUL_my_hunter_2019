/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** event.c
*/

#include "my.h"
#include "hunter.h"

void analyse_events(sfRenderWindow *window, sfEvent event, game_t *game,
    score_t *score)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        close_window(window, event);
        manage_mouse_click(event, game, score);
    }
}

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void manage_mouse_click(sfEvent event, game_t *game, score_t *score)
{
    if (event.type == sfEvtMouseMoved)
        game->mouse = (sfVector2f){event.mouseMove.x - 75,
        event.mouseMove.y - 75};
    if (event.type == sfEvtMouseButtonPressed) {
        if (game->coord.x <= event.mouseButton.x &&
            game->coord.y <= event.mouseButton.y &&
            game->coord.x + 66 >= event.mouseButton.x &&
            game->coord.y + 92 >= event.mouseButton.y) {
                game->coord.x = -50;
                game->coord.y = rand()%700;
                game->speed += 1;
                score->count += 1;
                sfMusic_play(game->sniper);
        }
    }
}