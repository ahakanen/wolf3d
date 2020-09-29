/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:38:22 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/29 16:45:22 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define CPUCORES 4
# define WIN_X 640
# define WIN_Y 512
# define TILE 64
# define STARTROTANGLES 64
# define END 0
# define ERRDEF 0
# define ERRMEM 1
# define ERRMAP 2
# define ERREMPTY 3
# define PI 3.1415926535
# define TWOPI 6.283185307
# define HALFPI 1.570796326
# define THREEHALVESPI 4.712388980
# define DEG 0.0174533
# define FRAMELIMIT 60

# if __APPLE__
#  define ESC 53
# endif

# if __linux__
#  define ESC 65307
#  define WASDUP 119
#  define WASDLEFT 97
#  define WASDDOWN 115
#  define WASDRIGHT 100
#  define SHIFT 65505
#  define SPACE 32
# endif

# include "mlx.h"
# include "../libft/includes/libft.h"
# include "../graphics/includes/graphics.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

typedef struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_window;

typedef struct	s_player
{
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		a;
	int			ai;
	int			movef;
	int			moveb;
	int			rotleft;
	int			rotright;
	double		speed;
}				t_player;

typedef struct	s_ray
{
	double		x;
	double		y;
	double		xo;
	double		yo;
	double		a;
	double		atan;
	double		ntan;
	double		disth;
	double		distv;
	double		rdist;
	int			mapx;
	int			mapy;
}				t_ray;

typedef struct	s_minimap
{
	t_vec2		*map;
	int			skip;
	int			x;
	int			y;
	int			winx;
	int			winy;
	int			size;
	int			bsize;
	int			bsizeh;
	void		*img;
	char		*img_ptr;
	t_imgptr	ptr;
	t_vec2		p;
	t_color		color;
	t_line		margleft;
	int			margstart;
	char		**blocks;
	t_vec2		blockv;
	t_vec2		poffset;
	t_vec2		boffset;
}				t_minimap;

typedef struct	s_params
{
	int			i;
	int			j;
	int			sizex;
	int			sizey;
	int			isfirst;
	char		**map;
	t_window	win;
	int			bpp;
	int			size;
	int			endian;
	void		*img;
	char		*img_ptr;
	t_imgptr	imgptr;
	t_player	p;
	t_ray		*rays;
	t_color		color;
	int			fov;
	double		onefov;
	int			*threadlim;
	int			limit;
	double		*tastart;
	int			mhelp;
	double		rstart;
	double		rstarthelp;
	double		height;
	double		offset;
	int			dof;
	t_minimap	mm;
	double		*rotarr;
	int			rotarrlast;
	t_color		floorclr;
	t_color		skyclr;
	clock_t		cstart;
	clock_t		cend;
	double		cframe;
	int			fps;
	clock_t		lstart;
	clock_t		lend;
	double		lcycle;
	double		llimitacc;
	double		llimit;
}				t_params;

typedef struct	s_tparams
{
	t_params	*params;
	int			*threadlim;
	double		*tastart;
	int			limit;
	double		rstart;
	double		rstarthelp;
	double		onefov;
	int			mhelp;
	t_imgptr	imgptr;
	int			offset;
	t_color		color;
	int			num;
}				t_tparams;

void			print_error(int type);
void			usage(void);
void			help(void);
void			validate(const int fd, t_params *params);
void			savemap(int fd, t_params *params);
void			initplayerstart(t_params *params);
void			openwindow(t_params *params);
int				press_key(int key, t_params *params);
int				release_key(int key, t_params *params);
void			movestart(int key, t_params *params);
void			movestop(int key, t_params *params);
void			movement(t_params *params, int dir);
void			rotation(t_params *params, int dir);
void			render(t_params *params);
t_ray			raycheckh(t_params *params, t_ray ray);
t_ray			raycheckv(t_params *params, t_ray ray);
void			getminimap(t_params *params);
void			drawminimap(t_params *params);
void			drawminiborder(t_params *params, int margstart);
void			initminimapblocks(t_params *params);
void			drawblock(t_params *params, int i, int j);
void			getblocksaroundplayer(t_params *params);
t_color			parsebcolor(char block);
void			initrotarr(t_params *params);
void			drawsky(t_params *params);
void			drawfloor(t_params *params);
t_tparams		threadhelp(t_params *params);
int				render_loop(t_params *params);
void			check(t_params *params);

#endif
