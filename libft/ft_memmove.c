/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:31:15 by jidrizi           #+#    #+#             */
/*   Updated: 2024/03/09 14:26:16 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ssrc;
	unsigned char	*sdst;
	size_t			x;

	ssrc = (unsigned char *)src;
	sdst = (unsigned char *)dst;
	x = 0;
	if (!sdst && !ssrc)
		return (NULL);
	if (sdst > ssrc)
	{
		while (len-- > 0)
		{
			sdst[len] = ssrc[len];
		}
	}
	else
	{
		while (x < len)
		{
			sdst[x] = ssrc[x];
			x++;
		}
	}
	return (dst);
}
