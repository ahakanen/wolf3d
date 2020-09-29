/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalemat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:54:03 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:18:22 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

t_mat2	scalemat2(double s)
{
	t_mat2	r;

	r = (t_mat2) {{\
				{s, 0}, \
				{0, s}\
				}};
	return (r);
}

t_mat3	scalemat3(double s)
{
	t_mat3	r;

	r = (t_mat3) {{\
				{s, 0, 0}, \
				{0, s, 0},
				{0, 0, s}\
				}};
	return (r);
}
