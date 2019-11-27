/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** hitler.c
*/

#include "my.h"

hitler_t get_hitler(hitler_t hitler)
{
    hitler.intr_hitler.top = 0;
    hitler.intr_hitler.left = 0;
    hitler.intr_hitler.width = 66;
    hitler.intr_hitler.height = 92;
    hitler.t_hitler = sfTexture_createFromFile("sprite/hitler.png", NULL);
    hitler.s_hitler = sfSprite_create();
    hitler.t_background = sfTexture_createFromFile("sprite/eagle.jpg", NULL);
    hitler.s_background = sfSprite_create();
    sfSprite_setTexture(hitler.s_background, hitler.t_background, sfTrue);
    hitler.t_sniper = sfTexture_createFromFile("sprite/sniper.png", NULL);
    hitler.s_sniper = sfSprite_create();
    sfSprite_setTexture(hitler.s_sniper, hitler.t_sniper, sfTrue);
    hitler.coord = (sfVector2f){-100, 0};
    hitler.clocks = sfClock_create();
    hitler.speed = 20;
    return (hitler);
}

void anim_sprite_hitler(hitler_t *hitler)
{
    if (hitler->intr_hitler.left < 182)
        hitler->intr_hitler.left += 91;
    else
        hitler->intr_hitler.left = 0;
}

void move_hitler(hitler_t *hitler)
{
    if (hitler->intr_hitler.left < 1920) {
        if (hitler->coord.x > 1920) {
            hitler->coord.x = -50;
            hitler->coord.y = rand()%700;
            hitler->speed = rand()%170;
        }
        hitler->coord.x = hitler->coord.x + hitler->speed;
        sfSprite_setPosition(hitler->s_hitler, hitler->coord);
    }
}

void display_hitler(hitler_t *hitler)
{
    anim_sprite_hitler(hitler);
    move_hitler(hitler);
    sfSprite_setTexture(hitler->s_hitler, hitler->t_hitler, sfTrue);
    sfSprite_setTextureRect(hitler->s_hitler, hitler->intr_hitler);
}