/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 21:06:12 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/18 17:19:28 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s)
	{
		while (start--)
			s++;
		str = (char *)malloc(len + 1);
		if (str)
		{
			while (len--)
				str[i++] = *(s++);
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
