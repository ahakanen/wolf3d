/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_memcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:23:12 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:14:21 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

void	*g_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (!dst || !src)
		return (dst);
	i = 0;
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char*)src;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dst);
}
