/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:15:59 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:15:18 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

t_mat2	transmat2(t_mat2 mat)
{
	t_mat2	r;

	r = (t_mat2) {{\
				{mat.m[0].x, mat.m[1].x}, \
				{mat.m[0].y, mat.m[1].y}\
				}};
	return (r);
}

t_mat3	transmat3(t_mat3 mat)
{
	t_mat3	r;

	r = (t_mat3) {{\
				{mat.m[0].x, mat.m[1].x, mat.m[2].x}, \
				{mat.m[0].y, mat.m[1].y, mat.m[2].y}, \
				{mat.m[0].z, mat.m[1].z, mat.m[2].z}\
				}};
	return (r);
}
