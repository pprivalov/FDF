/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 21:13:24 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/04 21:19:19 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (str)
		{
			while (*s1)
				str[i++] = *(s1++);
			while (*(s2))
				str[i++] = *(s2++);
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
