/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matxmat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:24:55 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/01 12:20:46 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

t_mat2	matxmat2(t_mat2 mat1, t_mat2 mat2)
{
	t_mat2	r;
	t_mat2	trans;

	trans = transmat2(mat2);
	r = (t_mat2) {{\
				{dotp2(mat1.m[0], trans.m[0]), dotp2(mat1.m[0], trans.m[1])},\
				{dotp2(mat1.m[1], trans.m[0]), dotp2(mat1.m[1], trans.m[1])}\
				}};
	return (r);
}

t_mat3	matxmat3(t_mat3 mat1, t_mat3 mat2)
{
	t_mat3	r;
	t_mat3	trans;

	trans = transmat3(mat2);
	r = (t_mat3) {{\
				{dotp3(mat1.m[0], trans.m[0]), dotp3(mat1.m[0], trans.m[1]), \
					dotp3(mat1.m[0], trans.m[2])},
				{dotp3(mat1.m[1], trans.m[0]), dotp3(mat1.m[1], trans.m[1]), \
					dotp3(mat1.m[1], trans.m[2])},
				{dotp3(mat1.m[2], trans.m[0]), dotp3(mat1.m[2], trans.m[1]), \
					dotp3(mat1.m[2], trans.m[2])}\
					}};
	return (r);
}
