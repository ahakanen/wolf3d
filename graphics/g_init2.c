/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_init2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:57:05 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:13:59 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

t_vec2		g_initvec2(double x, double y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vec3		g_initvec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_mat2		g_initmat2(t_vec2 v1, t_vec2 v2)
{
	t_mat2	mat;

	mat.m[0] = v1;
	mat.m[1] = v2;
	return (mat);
}

t_mat3		g_initmat3(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_mat3	mat;

	mat.m[0] = v1;
	mat.m[1] = v2;
	mat.m[2] = v3;
	return (mat);
}
