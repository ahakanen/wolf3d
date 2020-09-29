/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polylineshapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:06:49 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/01 14:21:33 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

t_polyline	*plmakesq(t_vec2 loc, int r)
{
	t_polyline	*pl;

	pl = plcreate(g_initvec2(loc.x - r, loc.y - r));
	pladdvertex(&pl, g_initvec2(loc.x + r, loc.y - r));
	pladdvertex(&pl, g_initvec2(loc.x + r, loc.y + r));
	pladdvertex(&pl, g_initvec2(loc.x - r, loc.y + r));
	return (pl);
}

t_polyline	*plmakerect(t_vec2 loc, t_vec2 dim)
{
	t_polyline	*pl;

	pl = plcreate(g_initvec2(loc.x - dim.x, loc.y - dim.y));
	pladdvertex(&pl, g_initvec2(loc.x + dim.x, loc.y - dim.y));
	pladdvertex(&pl, g_initvec2(loc.x + dim.x, loc.y + dim.y));
	pladdvertex(&pl, g_initvec2(loc.x - dim.x, loc.y + dim.y));
	return (pl);
}
