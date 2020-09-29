/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matxvec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:38:19 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:18:03 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

t_vec2	matxvec2(t_mat2 mat, t_vec2 vec)
{
	t_vec2	r;

	r = (t_vec2) {dotp2(mat.m[0], vec), dotp2(mat.m[1], vec)};
	return (r);
}

t_vec3	matxvec3(t_mat3 mat, t_vec3 vec)
{
	t_vec3	r;

	r = (t_vec3) {dotp3(mat.m[0], vec), dotp3(mat.m[1], vec), \
					dotp3(mat.m[2], vec)};
	return (r);
}
