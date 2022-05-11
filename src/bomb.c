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
#include <stdlib.h>

static	void	check_bombs(t_game *game, t_texstruct *textures) {

	for (int iter = 0; iter < textures->bomb_db.obj_c; iter++) {
		if (textures->bomb_db.objects[iter]->y > game->win_y - game->win_y / 2) {
			push_to_explosion_stack(textures->bomb_db.objects[iter]->x,
									textures->bomb_db.objects[iter]->y + 64,
									game, textures);
			free_object(textures->bomb_db.objects[iter]);
			textures->bomb_db.obj_c--;
			move_objects(&textures->bomb_db.objects[iter], textures->bomb_db.obj_c - iter);
		}
	}
}

/* This generates a bomb object, which is then returned as a pointer */
/* to the array of bombs. It first loads the texture, and then sets */
/* the x coordinate to a random value. The y coordinate */
/* is set to a position sufficiently high. */
static t_object	*gen_bomb(t_game *game) {
	t_object	*bomb;

	bomb = malloc(sizeof(t_object));
	bomb->obj_tex = LoadTextureFromImage(game->images.missile);
	bomb->x = GetRandomValue(0, game->win_x - bomb->obj_tex.width);
	bomb->y = game->win_y / 32 - bomb->obj_tex.height;
	return (bomb);
}

/* Handles the logic behind the (censored) missile strikes. */
/* If the array of missiles isn't already allocated within memory, then the */
/* function allocates the array using BOMB_LIMIT as a */
/* variable indicating the amount of memory to allocate. */
/* A static variables, time is used to count the amount of seconds */
/* since the last bomb was generated. This is used by the second */
/* if statement which waits for n seconds before executing */
/* and resetting the counter. */
/* A for loop is used to render the missiles within the */
/* game window. */
/* Then the check bomb function is used to handle logic based */
/* on the position of the bombs. */
void	bomb_logic(t_game *game, t_texstruct *textures) {
	static int	time;

	if (time + game->intensity > FPS * DEFAULT_INTENSITY) {
		if (textures->bomb_db.obj_c < BOMB_LIMIT) {
			textures->bomb_db.objects[textures->bomb_db.obj_c] = gen_bomb(game);
			textures->bomb_db.obj_c++;
		}
		time = 0;
	}
	for (int iter = 0; iter < textures->bomb_db.obj_c; iter++)
		DrawTexture(textures->bomb_db.objects[iter]->obj_tex,
					textures->bomb_db.objects[iter]->x,
					textures->bomb_db.objects[iter]->y += game->m_speed, WHITE);
	check_bombs(game, textures);
	time += 1;
}
