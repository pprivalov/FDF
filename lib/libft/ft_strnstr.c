/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:55:31 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/04 20:19:58 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	gone;
	size_t	i;

	i = 0;
	gone = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		while (i++ < len && *haystack == *needle && *haystack)
		{
			haystack++;
			needle++;
			gone++;
		}
		if (!*needle)
			return ((char *)(haystack - gone));
		haystack -= gone;
		i -= gone + 1;
		needle -= gone;
		gone = 0;
		i++;
		haystack++;
	}
	return (NULL);
}
