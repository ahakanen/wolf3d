/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyline2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 12:23:26 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:17:24 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

void	plshift(t_polyline **polyline, t_vec2 vec)
{
	t_polyline	*tmp;

	tmp = *polyline;
	while (tmp && tmp->vertex)
	{
		*(tmp->vertex) = vecadd2(vec, *(tmp->vertex));
		tmp = tmp->next;
	}
}

double	plgetminx(t_polyline **polyline)
{
	t_polyline	*tmp;
	double		r;

	tmp = *polyline;
	r = tmp->vertex->x;
	while (tmp && tmp->vertex)
	{
		if (tmp->vertex->x < r)
			r = tmp->vertex->x;
		tmp = tmp->next;
	}
	return (r);
}

double	plgetmaxx(t_polyline **polyline)
{
	t_polyline	*tmp;
	double		r;

	tmp = *polyline;
	r = tmp->vertex->x;
	while (tmp && tmp->vertex)
	{
		if (tmp->vertex->x > r)
			r = tmp->vertex->x;
		tmp = tmp->next;
	}
	return (r);
}

double	plgetminy(t_polyline **polyline)
{
	t_polyline	*tmp;
	double		r;

	tmp = *polyline;
	r = tmp->vertex->y;
	while (tmp && tmp->vertex)
	{
		if (tmp->vertex->y < r)
			r = tmp->vertex->y;
		tmp = tmp->next;
	}
	return (r);
}

double	plgetmaxy(t_polyline **polyline)
{
	t_polyline	*tmp;
	double		r;

	tmp = *polyline;
	r = tmp->vertex->y;
	while (tmp && tmp->vertex)
	{
		if (tmp->vertex->y > r)
			r = tmp->vertex->y;
		tmp = tmp->next;
	}
	return (r);
}
