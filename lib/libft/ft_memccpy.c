/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:14:39 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/04 20:13:11 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)d;
	src = (unsigned char *)s;
	while (n)
	{
		*dst = *src;
		if (*src == (unsigned char)c)
		{
			dst++;
			return (dst);
		}
		dst++;
		src++;
		n--;
	}
	return (NULL);
}
