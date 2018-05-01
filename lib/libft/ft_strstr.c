/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:00:03 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/04 20:19:37 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	gone;

	gone = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		while (*haystack == *needle && *haystack)
		{
			haystack++;
			needle++;
			gone++;
		}
		if (!*needle)
			return ((char *)(haystack - gone));
		haystack -= gone;
		needle -= gone;
		gone = 0;
		haystack++;
	}
	return (NULL);
}
