/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:42:40 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 17:28:41 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include "../../libft/includes/libft.h"

typedef struct	s_color
{
	int		b;
	int		g;
	int		r;
	int		a;
}				t_color;

typedef struct	s_vec2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct	s_mat2
{
	t_vec2	m[2];
}				t_mat2;

typedef struct	s_mat3
{
	t_vec3	m[3];
}				t_mat3;

typedef struct	s_line
{
	int		xa;
	int		ya;
	int		xb;
	int		yb;
}				t_line;

typedef struct	s_imgptr
{
	char	*img_ptr;
	int		sizex;
	int		sizey;
	int		size;
}				t_imgptr;

typedef struct	s_circleparams
{
	t_imgptr	ptr;
	t_vec2		loc;
	t_color		color;
	int			x;
	int			y;
	int			d;
}				t_circleparams;

typedef struct	s_dl
{
	int		dx;
	int		dy;
	int		p;
	int		x;
	int		y;
	double	m;
}				t_dl;

typedef struct	s_polyline
{
	t_vec2				*vertex;
	struct s_polyline	*next;
}				t_polyline;

double			dotp2(t_vec2 vec1, t_vec2 vec2);
double			dotp3(t_vec3 vec1, t_vec3 vec2);
void			drawcircle(t_imgptr ptr, t_vec2 loc, int r, t_color color);
void			drawcirclef(t_imgptr ptr, t_vec2 loc, int r, t_color color);
void			drawdot(t_imgptr ptr, int x, int y, t_color color);
void			drawline(t_imgptr ptr, t_line line, t_color color);
void			drawrect(t_imgptr ptr, t_vec2 loc, t_vec2 dim, t_color clr);
void			drawrectf(t_imgptr ptr, t_vec2 loc, t_vec2 dim, t_color clr);
void			drawsq(t_imgptr ptr, t_vec2 loc, int r, t_color clr);
void			drawsqf(t_imgptr ptr, t_vec2 loc, int r, t_color clr);
void			drawstraightx(t_imgptr ptr, t_line line, t_color color);
void			drawstraighty(t_imgptr ptr, t_line line, t_color color);
double			ft_abs(double i);
double			ft_fracpart(double num);
double			ft_sqrt(double num);
double			ft_sqrtn(double num, int end);
t_color			g_initcolor(int r, int g, int b, int a);
t_imgptr		g_initimgptr(char *img_ptr, int sizex, int sizey);
t_line			g_initline(int xa, int ya, int xb, int yb);
t_mat2			g_initmat2(t_vec2 v1, t_vec2 v2);
t_mat3			g_initmat3(t_vec3 v1, t_vec3 v2, t_vec3 v3);
t_vec2			g_initvec2(double x, double y);
t_vec3			g_initvec3(double x, double y, double z);
void			*g_memcpy(void *dst, const void *src, size_t n);
t_mat2			transmat2(t_mat2 mat);
t_mat3			transmat3(t_mat3 mat);
t_mat2			matxmat2(t_mat2 mat1, t_mat2 mat2);
t_mat3			matxmat3(t_mat3 mat1, t_mat3 mat2);
t_vec2			matxvec2(t_mat2 mat, t_vec2 vec);
t_vec3			matxvec3(t_mat3 mat, t_vec3 vec);
void			pladdvertex(t_polyline **polyline, t_vec2 vertex);
t_polyline		*plcreate(t_vec2 vertex);
void			pldel(t_polyline **polyline);
void			pldraw(t_polyline **polyline, t_imgptr ptr, t_color color);
void			plapplymat(t_polyline **polyline, t_mat2 mat);
void			plshiftapplymat(t_polyline **pl, t_mat2 mat);
void			plshiftxapplymat(t_polyline **pl, t_mat2 mat, t_vec2 shift);
void			plshift(t_polyline **polyline, t_vec2 vec);
double			plgetminx(t_polyline **polyline);
double			plgetmaxx(t_polyline **polyline);
double			plgetminy(t_polyline **polyline);
double			plgetmaxy(t_polyline **polyline);
double			plgetmidx(t_polyline **pl);
double			plgetmidy(t_polyline **pl);
t_polyline		*plmakesq(t_vec2 loc, int r);
t_polyline		*plmakerect(t_vec2 loc, t_vec2 dim);
void			reverseline(t_line *line);
t_mat2			rotmat2(double	a);
t_mat2			rotmat2common(char dir);
t_mat3			rotmatx3(double	a);
t_mat3			rotmaty3(double	a);
t_mat3			rotmatz3(double	a);
t_mat2			scalemat2(double s);
t_mat3			scalemat3(double s);
double			slope(int x0, int y0, int x1, int y1);
t_vec2			vecadd2(t_vec2 v1, t_vec2 v2);
t_vec2			vecsub2(t_vec2 v1, t_vec2 v2);
t_vec3			vecadd3(t_vec3 v1, t_vec3 v2);
t_vec3			vecsub3(t_vec3 v1, t_vec3 v2);
double			vlen(double ax, double ay, double bx, double by);

#endif
