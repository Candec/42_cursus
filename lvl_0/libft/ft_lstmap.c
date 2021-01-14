/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:43:37 by jibanez-          #+#    #+#             */
/*   Updated: 2021/01/13 11:12:12 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list *new;
	t_list *first;

	if (!f || !d)
		return (NULL);
	while (l)
	{
		if (!(new = ft_lstnew((*f)(l->content))))
		{
			while (first)
			{
				new = first->next;
				(*d)(first->content);
				free(first);
				first = new;
			}
			l = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		l = l->next;
	}
	return (first);
}
