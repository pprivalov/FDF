/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:56:17 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/04 20:59:27 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		str = ft_strdup(s);
		if (str)
		{
			while (str[i])
			{
				str[i] = f(i, *s);
				s++;
				i++;
			}
			return (str);
		}
	}
	return (NULL);
}
