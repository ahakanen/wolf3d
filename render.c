/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 09:59:53 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/29 09:09:36 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

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

static double	castray(t_params *params, double raystart, t_color *clr)
{
	t_ray	rayh;
	t_ray	rayv;
	double	rdist;
	double	fishfix;

	rayh = initray(params, raystart);
	rayh = raycheckh(params, rayh);
	rdist = rayh.disth;
	*clr = g_initcolor(0, 250, 0, 0);
	rayv = initray(params, raystart);
	rayv = raycheckv(params, rayv);
	if (rayv.distv < rayh.disth)
	{
		rdist = rayv.distv;
		*clr = g_initcolor(0, 0, 250, 0);
	}
	fishfix = params->p.a - raystart;
	rdist = rdist * cos(fishfix);
	return (rdist);
}

static void		*thread(void *param)
{
	double		rdist;
	double		height;
	int			start;
	t_tparams	*p;
	t_color		clr;

	p = (t_tparams*)param;
	start = p->limit * p->num;
	p->rstart = p->params->p.a - p->rstarthelp + p->tastart[p->num];
	while (start < p->threadlim[p->num])
	{
		rdist = castray(p->params, p->rstart, &clr);
		p->rstart += p->onefov;
		height = p->mhelp / rdist;
		drawline(p->imgptr, g_initline(start, p->offset - \
			height, start, p->offset + height), \
			clr);
		start++;
	}
}

static void		castrays(t_params *params)
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

void			render(t_params *params)
{
	params->cstart = clock();
	params->img = mlx_new_image(params->win.mlx_ptr, WIN_X, \
									WIN_Y);
	params->img_ptr = mlx_get_data_addr(params->img, &params->bpp, \
				&params->size, &params->endian);
	params->imgptr = g_initimgptr(params->img_ptr, WIN_X, WIN_Y);
	drawfloor(params);
	drawsky(params);
	castrays(params);
	drawminimap(params);
	mlx_destroy_image(params->win.mlx_ptr, params->img);
	params->cend = clock();
	params->cframe = (double)(params->cend - params->cstart) / CLOCKS_PER_SEC;
}
