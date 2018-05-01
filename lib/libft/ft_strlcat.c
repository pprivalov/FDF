/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:16:02 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/05 02:36:05 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict d, const char *restrict s, size_t ds)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	i = 0;
	j = 0;
	dlen = ft_strlen(d);
	slen = ft_strlen(s);
	if (dlen > ds)
		return (slen + ds);
	else
	{
		while (d[i])
			i++;
		while (s[j] && i < ds - 1)
		{
			d[i] = s[j];
			i++;
			j++;
		}
		d[i] = '\0';
		return (dlen + slen);
	}
}
