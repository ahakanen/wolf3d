/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:25:44 by ahakanen          #+#    #+#             */
/*   Updated: 2020/08/24 13:49:52 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

double	ft_sqrt(double num)
{
	int		i;
	double	j;

	i = 0;
	j = num / 2;
	while (i < 7)
	{
		j = j + num / j;
		j = 0.25 * j + num / j;
		i++;
	}
	return (j);
}
