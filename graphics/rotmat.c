/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotmat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:47:29 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:12:41 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

t_mat2	rotmat2(double a)
{
	t_mat2	r;
	double	cosa;
	double	sina;

	cosa = cos(a);
	sina = sin(a);
	r = (t_mat2) {{\
				{cosa, -sina}, \
				{sina, cosa}\
				}};
	return (r);
}

t_mat2	rotmat2common(char dir)
{
	t_mat2	r;

	if (dir == '+')
		r = (t_mat2) {{\
					{0, -1}, \
					{1, 0}\
					}};
	else if (dir == '-')
		r = (t_mat2) {{\
					{0, 1}, \
					{-1, 0}\
					}};
	else
		r = (t_mat2) {{\
					{0, -1}, \
					{-1, 0}\
					}};
	return (r);
}

t_mat3	rotmatx3(double a)
{
	t_mat3	r;
	double	cosa;
	double	sina;

	cosa = cos(a);
	sina = sin(a);
	r = (t_mat3) {{\
				{1, 0, 0}, \
				{0, cosa, -sina}, \
				{0, sina, cosa}\
				}};
	return (r);
}

t_mat3	rotmaty3(double a)
{
	t_mat3	r;
	double	cosa;
	double	sina;

	cosa = cos(a);
	sina = sin(a);
	r = (t_mat3) {{\
				{cosa, 0, sina}, \
				{0, 1, 0}, \
				{-sina, 0, cosa}\
				}};
	return (r);
}

t_mat3	rotmatz3(double a)
{
	t_mat3	r;
	double	cosa;
	double	sina;

	cosa = cos(a);
	sina = sin(a);
	r = (t_mat3) {{\
				{cosa, -sina, 0}, \
				{sina, cosa, 0}, \
				{0, 0, 1}\
				}};
	return (r);
}
