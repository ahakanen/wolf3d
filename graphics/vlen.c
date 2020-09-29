/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:40:08 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:15:41 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

double	vlen(double ax, double ay, double bx, double by)
{
	return (ft_sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}
