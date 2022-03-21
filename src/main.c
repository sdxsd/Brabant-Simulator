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

static int	init_game(t_game *game)
{
	game->win_x = WIDTH;
	game->win_y = HEIGHT;
	game->intensity = DEFAULT_INTENSITY;
	game->m_speed = DEFAULT_M_SPEED;
	game->game_time = 0;
	if (!load_textures(game, &game->images))
		return (0);
	InitAudioDevice();
	if (!load_audio(&game->audio))
		return (0);
	PlayMusicStream(game->audio.boom_bomb_dodging_dance);
	return (1);
}

int main (void) {
	t_game	g_data;

	if (!init_game(&g_data))
		return (1);
	game_start(&g_data);
	return (0);
}
