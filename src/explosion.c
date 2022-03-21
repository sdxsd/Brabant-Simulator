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

void	push_to_explosion_stack(int x, int y, t_game *game, t_texstruct *tex) {
	tex->xplosion_db.objects[tex->xplosion_db.obj_c] = malloc(sizeof(t_object));
	tex->xplosion_db.objects[tex->xplosion_db.obj_c]->obj_tex = LoadTextureFromImage(game->images.xplsion);
	tex->xplosion_db.objects[tex->xplosion_db.obj_c]->x = x;
	tex->xplosion_db.objects[tex->xplosion_db.obj_c]->y = y;
	tex->xplosion_db.obj_c++;
}

void	rndr_explosions(t_object_db *explosions) {
	static int	rndr_time;

	if (rndr_time / FPS > EXPLOSION_DECAY) {
		rndr_time = 0;
		free_object(explosions->objects[0]);
		move_objects(explosions->objects, explosions->obj_c);
		explosions->obj_c--;
	}
	for (int iter = 0; iter < explosions->obj_c; iter++)
	{
		DrawTexture(explosions->objects[iter]->obj_tex,
					explosions->objects[iter]->x,
					explosions->objects[iter]->y, WHITE);
		rndr_time++;
	}
}
