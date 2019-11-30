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
    sfSprite *s_star_1;
    sfSprite *s_star_2;
    sfSprite *s_star_3;

    sfTexture *t_hitler;
    sfTexture *t_background;
    sfTexture *t_sniper;
    sfTexture *t_star;

    sfIntRect intr_hitler;

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
    sfFont *font;
    char *res;
    int count;
    int loose;
}score_t;

int menu(game_t game, score_t score);
void analyse_events(sfRenderWindow *window, sfEvent event, game_t *game,
    score_t *score);
void close_window(sfRenderWindow *window, sfEvent event);
void manage_mouse_click(sfEvent event, game_t *game, score_t *score);
void game_clock(sfRenderWindow *window, game_t *game, score_t *score);
game_t get_hitler(game_t game);
score_t get_text(score_t score);
game_t get_star(game_t game);
void anim_sprite_hitler(game_t *game);
void move_hitler(game_t *game, score_t *score);
void draw_sprite(sfRenderWindow *window, game_t *game, score_t *score);
void draw_life(sfRenderWindow *window, game_t *game, score_t *score);
void display_hitler(game_t *game, score_t *score);
void display_score(score_t *score);
void help(void);
void destroy_all(sfRenderWindow *window, game_t game, score_t score);
char *my_itoa(int number);

#endif