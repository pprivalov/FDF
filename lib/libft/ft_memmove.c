/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 20:18:10 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/04 20:13:31 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	char		*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dest > source)
	{
		dest += len;
		source += len;
		while (len)
		{
			*(unsigned char *)--dest = *(unsigned char *)--source;
			len--;
		}
	}
	else
		while (len)
		{
			*(unsigned char *)dest++ = *(unsigned char *)source++;
			len--;
		}
	return (dst);
}
