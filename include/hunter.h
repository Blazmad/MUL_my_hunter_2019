/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** all prototypes
*/

#ifndef BTREE_H_
#define BTREE_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>

#include <stdlib.h>

typedef struct game
{
    sfSprite *s_hitler;
    sfSprite *s_background;
    sfSprite *s_sniper;

    sfTexture *t_hitler;
    sfTexture *t_background;
    sfTexture *t_sniper;

    sfIntRect intr_hitler;
    sfIntRect intr_background;
    sfIntRect intr_sniper;

    sfVector2f coord;
    sfVector2f mouse;
    int speed;

    sfClock *clocks;
    sfTime time;
    float seconds;

}game_t;

typedef struct score
{
    sfText *text;
    sfText *score;
    const sfFont *font;
    char *res;
    int count;
}score_t;

void close_window(sfRenderWindow *window, sfEvent event);
void manage_mouse_click(sfEvent event, game_t *hitler, score_t *score);
void analyse_events(sfRenderWindow *window, sfEvent event, game_t *hitler,
    score_t *score);
game_t get_hitler(game_t hitler);
void anim_sprite_hitler(game_t *hitler);
void move_hitler(game_t *hitler);
void clocks_hitler(game_t hitler);
void display_hitler(game_t *hitler);
score_t get_text(score_t score);
char *my_itoa(int number);
void display_score(score_t score);

#define ERROR 84
#define EXIT 0

#endif