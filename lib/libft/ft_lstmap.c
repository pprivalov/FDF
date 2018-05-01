/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:35:13 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/08 21:50:20 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*buf;

	if (lst && f)
	{
		ret = f(lst);
		lst = lst->next;
		buf = ret;
		while (lst)
		{
			ret->next = f(lst);
			if (ret->next)
				ret = ret->next;
			lst = lst->next;
		}
		ret = buf;
		return (ret);
	}
	return (NULL);
}
