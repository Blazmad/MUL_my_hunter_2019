/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** display_all.c
*/

#include "my.h"

void draw_life(sfRenderWindow *window, game_t *game, score_t *score)
{
    sfRenderWindow_drawSprite(window, game->s_background, NULL);
    sfRenderWindow_drawSprite(window, game->s_hitler, NULL);
    if (score->loose < 3) {
        sfSprite_setPosition(game->s_star_1, (sfVector2f){1450, 920});
        sfRenderWindow_drawSprite(window, game->s_star_1, NULL);
    }
    if (score->loose < 2) {
        sfSprite_setPosition(game->s_star_2, (sfVector2f){1580, 920});
        sfRenderWindow_drawSprite(window, game->s_star_2, NULL);
    }
    if (score->loose < 1) {
        sfSprite_setPosition(game->s_star_3, (sfVector2f){1710, 920});
        sfRenderWindow_drawSprite(window, game->s_star_3, NULL);
    }
}

void draw_sprite(sfRenderWindow *window, game_t *game, score_t *score)
{
    sfSprite_setPosition(game->s_sniper, game->mouse);
    sfRenderWindow_drawSprite(window, game->s_sniper, NULL);
    sfRenderWindow_drawText(window, score->text, NULL);
    sfRenderWindow_drawText(window, score->score, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void display_hitler(game_t *game, score_t *score)
{
    anim_sprite_hitler(game);
    move_hitler(game, score);
    sfSprite_setTexture(game->s_hitler, game->t_hitler, sfTrue);
    sfSprite_setTextureRect(game->s_hitler, game->intr_hitler);
}

void display_score(score_t *score)
{
    score->res = my_itoa(score->count);
    sfText_setCharacterSize(score->score, 50);
    sfText_setString(score->score, score->res);
    sfText_setFont(score->score, score->font);
    sfText_setPosition(score->score, (sfVector2f){885, 930});
}

void help(void)
{
    my_putstr("\nHitler Hunter created with CSFML by Clement Madzar.\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_hunter\n\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -h\t\tprint the usage and quit.\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("In this game, you must kill Hitler before he goes to the other");
    my_putstr(" side (to the left).\n");
    my_putstr("if Hitler manage to move to the other side, you'll lose a star.");
    my_putstr("\nYou have 3 stars. At 0 stars, YOU LOST.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("LEFT_CLICK_MOUSE\tshoot.");
}