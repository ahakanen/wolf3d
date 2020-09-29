/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadhelp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:34:30 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 17:54:18 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_tparams	threadhelp(t_params *params)
{
	t_tparams	tp;

	tp.params = params;
	tp.limit = params->limit;
	tp.threadlim = params->threadlim;
	tp.tastart = params->tastart;
	tp.rstarthelp = params->rstarthelp;
	tp.onefov = params->onefov;
	tp.mhelp = params->mhelp;
	tp.imgptr = params->imgptr;
	tp.offset = params->offset;
	tp.color = params->color;
	return (tp);
}
