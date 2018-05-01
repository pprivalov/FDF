/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 05:33:28 by pprivalo          #+#    #+#             */
/*   Updated: 2017/11/05 05:49:15 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;
	t_list	*next;

	if (alst)
	{
		buf = *alst;
		while (buf)
		{
			next = buf->next;
			del(buf->content, buf->content_size);
			free(buf);
			buf = next;
		}
		*alst = NULL;
	}
}
