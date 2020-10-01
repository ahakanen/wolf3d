/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 11:48:36 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/30 19:17:47 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	raycheckhhelp(t_params *params, t_ray *ray, int *dof)
{
	if (ray->a > PI)
	{
		ray->y = (((int)params->p.y >> 6) << 6) - 0.0001;
		ray->x = (params->p.y - ray->y) * ray->atan + params->p.x;
		ray->yo = -64;
		ray->xo = -ray->yo * ray->atan;
	}
	else if (ray->a < PI)
	{
		ray->y = (((int)params->p.y >> 6) << 6) + 64;
		ray->x = (params->p.y - ray->y) * ray->atan + params->p.x;
		ray->yo = 64;
		ray->xo = -ray->yo * ray->atan;
	}
	else
	{
		ray->x = params->p.x;
		ray->y = params->p.y;
		*dof = 128;
	}
}

t_ray		raycheckh(t_params *params, t_ray ray)
{
	int	dof;

	dof = 0;
	raycheckhhelp(params, &ray, &dof);
	while (dof < 128)
	{
		ray.mapx = (int)ray.x >> 6;
		ray.mapy = (int)ray.y >> 6;
		if (ray.mapx >= 0 && ray.mapy >= 0 && ray.mapx < params->sizex && \
		ray.mapy < params->sizey && params->map[ray.mapy][ray.mapx] == '1')
		{
			ray.disth = vlen(params->p.x, params->p.y, ray.x, ray.y);
			dof = 128;
		}
		else
		{
			ray.x += ray.xo;
			ray.y += ray.yo;
			dof++;
		}
	}
	return (ray);
}

static void	raycheckvhelp(t_params *params, t_ray *ray, int *dof)
{
	if (ray->a > HALFPI && ray->a < THREEHALVESPI)
	{
		ray->x = (((int)params->p.x >> 6) << 6) - 0.0001;
		ray->y = (params->p.x - ray->x) * ray->ntan + params->p.y;
		ray->xo = -64;
		ray->yo = -ray->xo * ray->ntan;
	}
	else if (ray->a < HALFPI || ray->a > THREEHALVESPI)
	{
		ray->x = (((int)params->p.x >> 6) << 6) + 64;
		ray->y = (params->p.x - ray->x) * ray->ntan + params->p.y;
		ray->xo = 64;
		ray->yo = -ray->xo * ray->ntan;
	}
	else
	{
		ray->x = params->p.x;
		ray->y = params->p.y;
		*dof = 128;
	}
}

t_ray		raycheckv(t_params *params, t_ray ray)
{
	int	dof;

	dof = 0;
	raycheckvhelp(params, &ray, &dof);
	while (dof < 128)
	{
		ray.mapx = (int)ray.x >> 6;
		ray.mapy = (int)ray.y >> 6;
		if (ray.mapx >= 0 && ray.mapy >= 0 && ray.mapx < params->sizex && \
		ray.mapy < params->sizey && params->map[ray.mapy][ray.mapx] == '1')
		{
			ray.distv = vlen(params->p.x, params->p.y, ray.x, ray.y);
			dof = 128;
		}
		else
		{
			ray.x += ray.xo;
			ray.y += ray.yo;
			dof++;
		}
	}
	return (ray);
}
