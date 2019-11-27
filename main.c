/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** main.c
*/

#include "my.h"

// void clocks_hitler(hitler_t hitler)
// {
//     hitler.time = sfClock_getElapsedTime(hitler.clocks);
//     hitler.seconds = hitler.time.microseconds / 1000000.0;
//     if (hitler.seconds >= 0.1) {
//         sfClock_restart(hitler.clocks);
//         display_hitler(&hitler);
//     }
// }

void destroy_all(sfRenderWindow *window, hitler_t hitler)
{
    sfSprite_destroy(hitler.s_hitler);
    sfTexture_destroy(hitler.t_hitler);
    sfRenderWindow_destroy(window);
}

void draw_sprite(sfRenderWindow *window, hitler_t *hitler)
{
    sfRenderWindow_drawSprite(window, hitler->s_background, NULL);
    sfRenderWindow_drawSprite(window, hitler->s_hitler, NULL);
    sfSprite_setPosition(hitler->s_sniper, hitler->mouse);
    sfRenderWindow_drawSprite(window, hitler->s_sniper, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

int menu(hitler_t hitler)
{
	sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "window", sfResize |
        sfClose, NULL);
    sfEvent event;

    sfRenderWindow_setFramerateLimit(window, 30);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window, event, &hitler);
        // clocks_hitler(hitler);
        hitler.time = sfClock_getElapsedTime(hitler.clocks);
        hitler.seconds = hitler.time.microseconds / 1000000.0;
        if (hitler.seconds >= 0.1) {
            sfClock_restart(hitler.clocks);
            display_hitler(&hitler);
        }
        draw_sprite(window, &hitler);
    }
    destroy_all(window, hitler);
    return (0);
}

int main(void)
{
    hitler_t hitler;

    hitler = get_hitler(hitler);
    menu(hitler);
	return (0);
}