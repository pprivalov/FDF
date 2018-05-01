/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 21:20:42 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/16 21:12:11 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	l;
	size_t	i;

	i = 0;
	if (s)
	{
		l = ft_strlen(s);
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		while ((s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t') && l)
			l--;
		if (l >= i)
		{
			str = ft_strsub(s, i, l - i);
			return (str);
		}
		else
		{
			str = ft_strnew(0);
			return (str);
		}
	}
	return (NULL);
}
