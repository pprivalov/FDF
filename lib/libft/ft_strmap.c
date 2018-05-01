/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:40:06 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/05 06:13:59 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;

	if (s && f)
	{
		len = ft_strlen(s);
		str = ft_strdup(s);
		if (str)
		{
			while (*str)
			{
				*str = f(*s);
				str++;
				s++;
			}
			return (str - len);
		}
	}
	return (NULL);
}
