/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:17:20 by ahakanen          #+#    #+#             */
/*   Updated: 2020/08/24 13:07:51 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

void	reverseline(t_line *line)
{
	int	tmp1;
	int tmp2;

	tmp1 = line->xa;
	tmp2 = line->ya;
	line->xa = line->xb;
	line->ya = line->yb;
	line->xb = tmp1;
	line->yb = tmp2;
}
