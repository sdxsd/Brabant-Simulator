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

#ifndef MAIN_H
# define MAIN_H
# define TITLE "Brabants Simulator"
# define WIDTH	1280
# define HEIGHT 768
# define FPS 60
# define SPEED 20.0f
# define DEFAULT_INTENSITY 5
# define INTENSITY_STEP 30
# define DEFAULT_M_SPEED 2
# define BOMB_LIMIT 8
# define EXPLOSION_DECAY 2
# define GAME_LOSS -1
# define GAME_WIN 1
# define MAX_TIME 120
# include <raylib.h>

/* Datastructure containing the audio data */
/* of the game. */
/* 0: Played at game loss. */
/* 1: Played at game win. */
/* 2: Played while game is active. */
typedef struct audiofiles {
	Music	boom_bomb_dodging_dance;
}	t_audiofiles;

/* Datastructure containing */
/* object data, including a tex instance */
/* and coordinates. */
typedef	struct object {
	Texture2D	obj_tex;
	Rectangle	obj_coll;
	float		x;
	float		y;
}	t_object;

/* Datastructure containing a database */
/* of all objects (explosions/bombs) currently in the game. */
typedef	struct object_db {
	int			obj_c;
	t_object	**objects;
}	t_object_db;

/* Contains texturedata, which can be directly */
/* drawn to the screen. However, a texture */
/* can only be drawn to the screen once. */
/* Hence, two t_object_db variables are used */
/* to store sprites and their associated */
/* data which have to be drawn two or more */
/* times at the same time. */
typedef struct texstruct {
	t_object_db	bomb_db;
	t_object_db	xplosion_db;
	Texture2D	bckgrnd;
	Texture2D	terrain;
	Texture2D	plyr;
	Rectangle	plyr_coll;
}	t_texstruct;

/* Datastructure storing the visual */
/* game assets. */
/* Texture2D variables are generated from these assets */
/* which are then drawn to the screen */
typedef struct imagedata {
	Image		player;
	Image		missile;
	Image		xplsion;
	Image		bckgrnd;
	Image		terrain;
}	t_imagedata;

/* Datastructure that holds */
/* the variables collectively */
/* making up the state of */
/* the game. */
typedef struct s_game {
	int				win_x;
	int				win_y;
	float			plyr_x;
	float			plyr_y;
	int				intensity;
	int				game_time;
	float			m_speed;
	t_imagedata		images;
	t_audiofiles	audio;
}	t_game;

/* AUDIO FUNCTIONS (audio.c) */
int	load_audio(t_audiofiles *audiodata);

/* GRAPHICS FUNCTIONS (render.c) */
int	load_textures(t_game *game, t_imagedata *images);
int	game_start(t_game *game);

/* BOMB FUNCTIONS (bomb.c) */
void	bomb_logic(t_game *game, t_texstruct *textures);

/* EXPLOSION FUNCTIONS (explosion.c) */
void	push_to_explosion_stack(int x, int y, t_game *game, t_texstruct *tex);
void	rndr_explosions(t_object_db *explosions);

/* OBJECT FUNCTIONS (object.c) */
t_object_db	*init_object_db(t_object_db *objects, int count);
void	free_object(t_object *object);
void	move_objects(t_object **objects, int obj_c);

/* TIME FUNCTIONS (time.c) */
void	handle_time(t_game *game);

/* COLLISION FUNCTIONS (collision.c) */
int	update_collision(t_game *game, t_texstruct *textures);
int	handle_collision(t_texstruct *textures);

/* EXIT FUNCTIONS */
int	game_exit(int state);

#endif // MAIN_H
