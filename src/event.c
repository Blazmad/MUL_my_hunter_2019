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

void manage_mouse_click(sfEvent event, hitler_t *hitler)
{
    if (event.type == sfEvtMouseMoved)
        hitler->mouse = (sfVector2f){event.mouseMove.x - 75,
        event.mouseMove.y - 75};
    if (event.type == sfEvtMouseButtonPressed) {
        if (hitler->coord.x <= event.mouseButton.x &&
            hitler->coord.y <= event.mouseButton.y &&
            hitler->coord.x + 66 >= event.mouseButton.x &&
            hitler->coord.y + 92 >= event.mouseButton.y) {
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
            manage_mouse_click(event, hitler);
     }
}