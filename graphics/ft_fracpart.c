/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fracpart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:25:52 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:16:22 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

double	ft_fracpart(double num)
{
	double	r;

	if (num >= 0)
		r = num - floor(num);
	else
		r = num + floor(num);
	if (r + 0.00000001 >= 1 || r - 0.00000001 <= -1)
		r = 0;
	return (r);
}
