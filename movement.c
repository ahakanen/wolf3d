/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:01:53 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/22 19:47:25 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	strafe(t_params *params, int dir, double old, t_vec2 oldv)
{
	t_vec2	newv;

	if (dir == Q)
	{
		params->p.a -= HALFPI;
		if (params->p.a < 0)
			params->p.a += TWOPI;
		newv = matxvec2(rotmat2(-HALFPI), oldv);
	}
	if (dir == E)
	{
		params->p.a += HALFPI;
		if (params->p.a >= TWOPI)
			params->p.a -= TWOPI;
		newv = matxvec2(rotmat2(HALFPI), oldv);
	}
	params->p.dx = newv.x;
	params->p.dy = newv.y;
	checkcollisionxf(params);
	checkcollisionyf(params);
	params->p.a = old;
	params->p.dx = oldv.x;
	params->p.dy = oldv.y;
}

void		rotation(t_params *params, int dir)
{
	if (dir == WASDLEFT)
	{
		params->p.ai -= 3;
		if (params->p.ai < 0)
			params->p.ai = params->rotarrlast - 3;
		params->p.a = params->rotarr[params->p.ai];
		params->p.dx = params->rotarr[params->p.ai + 1];
		params->p.dy = params->rotarr[params->p.ai + 2];
	}
	if (dir == WASDRIGHT)
	{
		params->p.ai += 3;
		if (params->rotarrlast <= params->p.ai)
			params->p.ai = 0;
		params->p.a = params->rotarr[params->p.ai];
		params->p.dx = params->rotarr[params->p.ai + 1];
		params->p.dy = params->rotarr[params->p.ai + 2];
	}
}

void		movement(t_params *params, int dir)
{
	double	old;
	t_vec2	oldv;

	if (dir == WASDUP)
	{
		checkcollisionxf(params);
		checkcollisionyf(params);
	}
	if (dir == WASDDOWN)
	{
		checkcollisionxb(params);
		checkcollisionyb(params);
	}
	if (dir == Q || dir == E)
	{
		old = params->p.a;
		oldv = g_initvec2(params->p.dx, params->p.dy);
		strafe(params, dir, old, oldv);
	}
}

void		movestop(int key, t_params *params)
{
	if (key == WASDUP)
		params->p.movef = 0;
	if (key == WASDDOWN)
		params->p.moveb = 0;
	if (key == WASDLEFT)
		params->p.rotleft = 0;
	if (key == WASDRIGHT)
		params->p.rotright = 0;
	if (key == Q)
		params->p.strafeleft = 0;
	if (key == E)
		params->p.straferight = 0;
}

void		movestart(int key, t_params *params)
{
	if (key == WASDUP)
		params->p.movef = 1;
	if (key == WASDDOWN)
		params->p.moveb = 1;
	if (key == WASDLEFT)
		params->p.rotleft = 1;
	if (key == WASDRIGHT)
		params->p.rotright = 1;
	if (key == Q)
		params->p.strafeleft = 1;
	if (key == E)
		params->p.straferight = 1;
}
