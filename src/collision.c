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

int	handle_collision(t_texstruct *textures) {
	bool	collision;

	for (int iter = 0; iter < textures->bomb_db.obj_c; iter++) {
		collision = CheckCollisionRecs(textures->plyr_coll, textures->bomb_db.objects[iter]->obj_coll);
		if (collision)
			return (1);
	}
	return (0);
}

/* This function is a bit of a mess. */
/* Will write documentation when it's cleaned. */
int	update_collision(t_game *game, t_texstruct *textures) {
	textures->plyr_coll.x = game->plyr_x;
	textures->plyr_coll.y = game->plyr_y;
	textures->plyr.width = textures->plyr.width;
	textures->plyr.height = textures->plyr.height;
	for (int iter = 0; iter < textures->bomb_db.obj_c; iter++) {
		textures->bomb_db.objects[iter]->obj_coll.x =
			textures->bomb_db.objects[iter]->x -
			textures->bomb_db.objects[iter]->obj_tex.width;
		textures->bomb_db.objects[iter]->obj_coll.y =
			textures->bomb_db.objects[iter]->y;
		textures->bomb_db.objects[iter]->obj_coll.width =
			textures->bomb_db.objects[iter]->obj_tex.width;
		textures->bomb_db.objects[iter]->obj_coll.height =
			textures->bomb_db.objects[iter]->obj_tex.height;
	}
	return (0);
}
