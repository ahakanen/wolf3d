/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyline3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:18:21 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:15:31 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

double	plgetmidx(t_polyline **pl)
{
	return (plgetmaxx(pl) - (plgetmaxx(pl) - plgetminx(pl)) / 2);
}

double	plgetmidy(t_polyline **pl)
{
	return (plgetmaxy(pl) - (plgetmaxy(pl) - plgetminy(pl)) / 2);
}

void	plshiftapplymat(t_polyline **pl, t_mat2 mat)
{
	double	midx;
	double	midy;

	midx = plgetmidx(pl);
	midy = plgetmidy(pl);
	plshift(pl, g_initvec2(-midx, -midy));
	plapplymat(pl, mat);
	plshift(pl, g_initvec2(midx, midy));
}

void	plshiftxapplymat(t_polyline **pl, t_mat2 mat, t_vec2 shift)
{
	plshift(pl, g_initvec2(-shift.x, -shift.y));
	plapplymat(pl, mat);
	plshift(pl, shift);
}
