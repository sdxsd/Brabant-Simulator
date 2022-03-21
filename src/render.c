/*
THIS FILE IS LICENSED UNDER THE GNU GPLv3

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>

The definition of Free Software is as follows:
				- The freedom to run the program, for any purpose.
				- The freedom to study how the program works, and adapt it to your needs.
				- The freedom to redistribute copies so you can help your neighbor.
				- The freedom to improve the program, and release
				your improvements to the public, so that the whole community benefits.

A program is free software if users have all of these freedoms.
*/

#include "../includes/main.h"
#include <stdio.h>

static int	handle_input(t_game *game) {
	if (IsKeyDown(KEY_RIGHT))
		game->plyr_x += SPEED;
	if (IsKeyDown(KEY_LEFT))
		game->plyr_x -= SPEED;
	if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_SPACE))
		game->plyr_x -= SPEED * 2;
	if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_SPACE))
		game->plyr_x += SPEED * 2;
	return (1);
}

static int	rndr_bckgrnd(Texture2D *bck, Texture2D *terr) {
	DrawTexture(*bck, 0, 0, WHITE);
	DrawTexture(*terr, 0, 0, WHITE);
	return (0);
}

static void	algemeen_init(t_texstruct *textures, t_game *game) {
	InitWindow(game->win_x, game->win_y, TITLE);
	SetTargetFPS(FPS);
	textures->plyr = LoadTextureFromImage(game->images.player);
	textures->bckgrnd = LoadTextureFromImage(game->images.bckgrnd);
	textures->terrain = LoadTextureFromImage(game->images.terrain);
	game->plyr_x = (game->win_x / 2 - textures->plyr.width);
	game->plyr_y = (game->win_y / 1 - textures->plyr.height - 64);
	init_object_db(&textures->bomb_db, BOMB_LIMIT);
	init_object_db(&textures->xplosion_db, BOMB_LIMIT);
}

static void	rndr_loop(t_game *game, t_texstruct *textures) {
	game->game_time++;
	rndr_bckgrnd(&textures->bckgrnd, &textures->terrain);
	DrawTexture(textures->plyr, game->plyr_x, game->plyr_y, WHITE);
	bomb_logic(game, textures);
	update_collision(game, textures);
	if (handle_collision(textures)) {
		game_exit(GAME_LOSS);
	}
	rndr_explosions(&textures->xplosion_db);
	handle_time(game);
}

int	game_start(t_game *game) {
	t_texstruct	textures;

	algemeen_init(&textures, game);
	while (!WindowShouldClose()) {
		UpdateMusicStream(game->audio.boom_bomb_dodging_dance);
		handle_input(game);
		BeginDrawing();
			rndr_loop(game, &textures);
		EndDrawing();
	}
	return (1);
}
