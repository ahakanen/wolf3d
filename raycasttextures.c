/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasttextures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:32:21 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/07 19:24:18 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_ray	initray(t_params *params, double raystart)
{
	t_ray ray;

	ray.a = raystart;
	if (ray.a > TWOPI)
		ray.a -= TWOPI;
	if (ray.a < 0)
		ray.a += TWOPI;
	ray.atan = -1 / tan(ray.a);
	ray.ntan = -tan(ray.a);
	ray.x = 0;
	ray.y = 0;
	ray.xo = 0;
	ray.yo = 0;
	ray.disth = 100000000000;
	ray.distv = 100000000000;
	return (ray);
}

static t_rtex	castray(t_params *params, double raystart)
{
	t_ray	rayh;
	t_ray	rayv;
	t_rtex	rtex;

	rayh = initray(params, raystart);
	rayh = raycheckh(params, rayh);
	rtex.rdist = rayh.disth;
	rtex.offset = (int)rayh.x % TILE;
	rayv = initray(params, raystart);
	rayv = raycheckv(params, rayv);
	if (rayv.distv < rayh.disth)
	{
		rtex.rdist = rayv.distv;
		rtex.offset = (int)rayv.y % TILE;
		rtex.tex = parsebtex(params, params->map[rayv.mapy][rayv.mapx]);
	}
	else
		rtex.tex = parsebtex(params, params->map[rayh.mapy][rayh.mapx]);
	rtex.rdist = rtex.rdist * cos(params->p.a - raystart);
	return (rtex);
}

static void		*thread(void *param)
{
	t_rtex		rtex;
	t_rp		rp;
	t_tparams	*p;

	p = (t_tparams*)param;
	rp.start = p->limit * p->num;
	drawfloortex(p->params, rp.start, p->threadlim[p->num], p->num);
	p->rstart = p->params->p.a - p->rstarthelp + p->tastart[p->num];
	while (rp.start < p->threadlim[p->num])
	{
		rtex = castray(p->params, p->rstart);
		p->rstart += p->onefov;
		rp.height = p->mhelp / rtex.rdist;
		if (rp.height > p->params->maxheight)
			rp.height = p->params->maxheight;
		drawtex(p, rtex, rp);
		rp.start++;
	}
}

void		castraystex(t_params *params)
{
	pthread_t	threads[CPUCORES];
	t_tparams	tp[CPUCORES];
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < CPUCORES)
	{
		tp[i] = threadhelp(params);
		tp[i].num = i;
		pthread_create(&threads[i], NULL, thread, &tp[i]);
		i++;
	}
	while (j < CPUCORES)
	{
		pthread_join(threads[j], NULL);
		j++;
	}
	mlx_put_image_to_window(params->win.mlx_ptr, \
		params->win.win_ptr, params->img, 0, 0);
}