/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 20:18:16 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/18 20:18:19 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	size_t	i;
	t_list	*tmp;

	if (begin_list)
	{
		i = 0;
		tmp = begin_list;
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
	return (0);
}
