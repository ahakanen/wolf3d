/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:16:09 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:16:44 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

t_vec2	vecadd2(t_vec2 v1, t_vec2 v2)
{
	t_vec2	r;

	r = (t_vec2) {v1.x + v2.x, v1.y + v2.y};
	return (r);
}

t_vec2	vecsub2(t_vec2 v1, t_vec2 v2)
{
	t_vec2	r;

	r = (t_vec2) {v1.x - v2.x, v1.y - v2.y};
	return (r);
}

t_vec3	vecadd3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	r;

	r = (t_vec3) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
	return (r);
}

t_vec3	vecsub3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	r;

	r = (t_vec3) {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
	return (r);
}
