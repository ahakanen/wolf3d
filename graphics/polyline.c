/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:35:13 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:09:13 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

t_polyline	*plcreate(t_vec2 vertex)
{
	t_polyline	*polyline;

	if (!(polyline = (t_polyline *)malloc(sizeof(t_polyline))))
		return (NULL);
	polyline->vertex = malloc(sizeof(t_vec2));
	if (polyline->vertex == NULL)
	{
		free(polyline);
		return (NULL);
	}
	g_memcpy(polyline->vertex, &vertex, sizeof(t_vec2));
	polyline->next = NULL;
	return (polyline);
}

void		pladdvertex(t_polyline **polyline, t_vec2 vertex)
{
	t_polyline	*tmp;

	tmp = *polyline;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = plcreate(vertex);
}

void		pldel(t_polyline **polyline)
{
	t_polyline	*tmp;
	t_polyline	*next;

	tmp = *polyline;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	polyline = NULL;
}

void		plapplymat(t_polyline **polyline, t_mat2 mat)
{
	t_polyline	*tmp;

	tmp = *polyline;
	while (tmp && tmp->vertex)
	{
		*(tmp->vertex) = matxvec2(mat, *(tmp->vertex));
		tmp = tmp->next;
	}
}

void		pldraw(t_polyline **polyline, t_imgptr ptr, t_color color)
{
	t_vec2		*first;
	t_vec2		*earlier;
	t_polyline	*tmp;
	int			isfirst;

	tmp = *polyline;
	isfirst = 1;
	if (tmp->next && tmp->vertex)
	{
		first = tmp->vertex;
		while (tmp)
		{
			if (isfirst != 1)
				drawline(ptr, g_initline(earlier->x, earlier->y, \
						tmp->vertex->x, tmp->vertex->y), color);
			else
				isfirst = 0;
			earlier = tmp->vertex;
			tmp = tmp->next;
		}
		drawline(ptr, g_initline(first->x, first->y, earlier->x, \
					earlier->y), color);
	}
}
