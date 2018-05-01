/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 04:54:11 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/09 18:55:54 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)ft_memalloc(sizeof(t_list));
	if (node)
	{
		node->content = ft_memalloc(content_size);
		if (content && node->content)
		{
			ft_memcpy(node->content, content, content_size);
			node->content_size = content_size;
		}
		else
		{
			node->content = NULL;
			node->content_size = 0;
		}
		node->next = NULL;
		return (node);
	}
	free(node);
	return (NULL);
}
