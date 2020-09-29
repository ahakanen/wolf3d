/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slope.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:07:42 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:16:02 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

double	slope(int x0, int y0, int x1, int y1)
{
	return ((double)(y1 - y0) / (double)(x1 - x0));
}
