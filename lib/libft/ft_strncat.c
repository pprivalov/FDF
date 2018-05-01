/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:12:57 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/04 20:17:45 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;
	size_t	len1;

	i = 0;
	len1 = 0;
	while (s1[i])
	{
		len1++;
		i++;
	}
	while ((i - len1) < n && s2[i - len1])
	{
		s1[i] = s2[i - len1];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
