/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:03:02 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/04 20:21:57 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	nbr;
	unsigned long long	max;
	int					sign;

	sign = 1;
	nbr = 0;
	max = 9223372036854775807;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*(str++) - 48);
		if (nbr > max && sign == 1)
			return (-1);
		if (nbr > max + 1 && sign == -1)
			return (0);
	}
	return (sign * nbr);
}
