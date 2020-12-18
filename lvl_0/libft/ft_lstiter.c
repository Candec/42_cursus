/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:05:42 by jibanez-          #+#    #+#             */
/*   Updated: 2020/12/17 17:05:42 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return (NULL);
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
