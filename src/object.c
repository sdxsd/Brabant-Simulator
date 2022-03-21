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

t_object_db	*init_object_db(t_object_db *objects, int count) {
	objects->obj_c = 0;
	objects->objects = malloc(sizeof(t_object *) * count);
	return (objects);
}

/* Deallocates memory associated with the bomb object. */
/* Normally called when the game ends, or the bomb has exploded. */
void	free_object(t_object *object)
{
	UnloadTexture(object->obj_tex);
	free(object);
}

/* Since the rendering of the objects happens in a stack based manner, bombs are */
/* pushed on to the stack, while bombs at the bottom hit the */
/* ground, explode, and are deallocated; Gaps at the start of the */
/* array holding the bombs are generated. This function rectifies that */
/* by iteratively moving each bomb down by one, and is only called */
/* when a bomb has been detonated. This fixes the problem */
/* of attempting to render a bomb which no longer exists */
/* which would cause a segmentation fault. */
void	move_objects(t_object **objects, int obj_c) {
	for (int iter = 0; iter < obj_c; iter++)
			objects[iter] = objects[iter + 1];
}
