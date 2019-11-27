/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** all prototypes
*/

#ifndef BTREE_H_
#define BTREE_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>

typedef struct hitler
{
    // sfSprite *sprite_background;
    sfSprite *s_hitler;
    sfSprite *s_background;
    sfTexture *t_hitler;
    sfTexture *t_background;
    sfIntRect intr_hitler;
    sfIntRect intr_background;
    sfVector2f coord;
    // sfSprite *s_sniper;
    // sfTexture *t_sniper;
    // sfIntRect intr_sniper;
    // sfVector2f mouse;
    int speed;
    sfClock *clocks;
    sfTime time;
    float seconds;
}hitler_t;

void close_window(sfRenderWindow *window, sfEvent event);
void manage_mouse_click(sfEvent event, sfRenderWindow *window, hitler_t *hitler);
void analyse_events(sfRenderWindow *window, sfEvent event, hitler_t *hitler);
hitler_t get_hitler(hitler_t hitler);
void anim_sprite_hitler(hitler_t *hitler);
void move_hitler(hitler_t *hitler);
void clocks_hitler(hitler_t hitler);
void display_hitler(hitler_t *hitler);

#define ERROR 84
#define EXIT 0

#endif