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

int	load_textures(t_game *game, t_imagedata *images)
{
	images->player = LoadImage("img/plyr.png");
	images->missile = LoadImage("img/bomb.png");
	images->xplsion = LoadImage("img/explosion.png");
	images->terrain = LoadImage("img/terrain.png");
	images->bckgrnd = LoadImage("img/sky.png");
	ImageResize(&images->bckgrnd, game->win_x, game->win_y);
	ImageResize(&images->terrain, game->win_x, game->win_y);
	ImageResize(&game->images.missile, 128, 256);
	ImageResize(&game->images.xplsion, 256, 256);
	return (1);
}
