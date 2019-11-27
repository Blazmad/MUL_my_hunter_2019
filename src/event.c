/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** event.c
*/

#include "my.h"
#include "hunter.h"

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void manage_mouse_click(sfEvent event, sfRenderWindow *window, hitler_t *hitler)
{
    // if (event.type == sfEvtMouseMoved) {
    //     hitler->mouse = (sfVector2f){event.mouseMove.x, event.mouseMove.y};
    //     // hitler->mouse.y = event.mouseMove.y;
    //     printf("%f   ,   %f\n", hitler->mouse.x, hitler->mouse.y);
    // }
    if (event.type == sfEvtMouseButtonPressed) {
        if (hitler->coord.x + 30 <= event.mouseButton.x &&
            hitler->coord.y + 30 <= event.mouseButton.y &&
            hitler->coord.x + 30 >= event.mouseButton.y &&
            hitler->coord.y + 30 >= event.mouseButton.x) {
                hitler->coord.x = -50;
                hitler->coord.y = rand()%700;
                hitler->speed = rand()%170;
        }
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event, hitler_t *hitler)
{
     while (sfRenderWindow_pollEvent(window, &event)) {
            close_window(window, event);
            manage_mouse_click(event, window, hitler);
     }
}