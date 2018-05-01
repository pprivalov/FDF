/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 23:29:11 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/05 01:41:01 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int		len;

	len = 0;
	if (!n)
		len = 1;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	len = ft_nbrlen(n);
	str = (char *)ft_memalloc(len + 1);
	if (str)
	{
		str[len] = '\0';
		if (n < 0)
		{
			sign = -1;
			str[0] = '-';
		}
		else if (!n)
			str[0] = 48;
		while (n)
		{
			str[--len] = sign * (n % 10) + 48;
			n = n / 10;
		}
	}
	return (str);
}
