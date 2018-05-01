/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 21:03:34 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/04 21:05:01 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		cmp;

	if (s1 && s2)
	{
		cmp = ft_strncmp(s1, s2, n);
		if (cmp == 0)
			return (1);
	}
	return (0);
}
