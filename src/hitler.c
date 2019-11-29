/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** hitler.c
*/

#include "my.h"

game_t get_hitler(game_t game)
{
    game.intr_hitler.top = 0;
    game.intr_hitler.left = 0;
    game.intr_hitler.width = 66;
    game.intr_hitler.height = 92;
    game.t_hitler = sfTexture_createFromFile("sprite/hitler.png", NULL);
    game.s_hitler = sfSprite_create();
    game.t_background = sfTexture_createFromFile("sprite/eagle.jpg", NULL);
    game.s_background = sfSprite_create();
    sfSprite_setTexture(game.s_background, game.t_background, sfTrue);
    game.t_sniper = sfTexture_createFromFile("sprite/sniper.png", NULL);
    game.s_sniper = sfSprite_create();
    sfSprite_setTexture(game.s_sniper, game.t_sniper, sfTrue);
    game.coord = (sfVector2f){-100, 0};
    game.clocks = sfClock_create();
    game.speed = 20;
    return (game);
}

game_t get_star(game_t game)
{
    game.t_star = sfTexture_createFromFile("sprite/star.png", NULL);
    game.s_star_1 = sfSprite_create();
    sfSprite_setTexture(game.s_star_1, game.t_star, sfTrue);
    game.s_star_2 = sfSprite_create();
    sfSprite_setTexture(game.s_star_2, game.t_star, sfTrue);
    game.s_star_3 = sfSprite_create();
    sfSprite_setTexture(game.s_star_3, game.t_star, sfTrue);
    return (game);
}

score_t get_text(score_t score)
{
    score.score = sfText_create();
    score.text = sfText_create();
    score.font = sfFont_createFromFile("font/nazi_font.ttf");
    score.count = 0;
    score.res = 0;
    sfText_setCharacterSize(score.text, 50);
    sfText_setString(score.text, "|Best Score :\t\t\t\t|SCORE :\t\t\t\t\t|Life :");
    sfText_setFont(score.text, score.font);
    sfText_setPosition(score.text, (sfVector2f){70, 930});
    return (score);
}

void anim_sprite_hitler(game_t *game)
{
    if (game->intr_hitler.left < 182)
        game->intr_hitler.left += 91;
    else
        game->intr_hitler.left = 0;
}

void move_hitler(game_t *game, score_t *score)
{
    if (game->intr_hitler.left < 1920) {
        if (game->coord.x > 1920) {
            game->coord.x = -50;
            game->coord.y = rand()%700;
            score->loose += 1;
        }
        game->coord.x = game->coord.x + game->speed;
        sfSprite_setPosition(game->s_hitler, game->coord);
    }
}