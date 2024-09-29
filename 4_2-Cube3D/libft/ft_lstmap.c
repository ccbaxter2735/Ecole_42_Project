/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:37:58 by terussar          #+#    #+#             */
/*   Updated: 2022/11/30 13:39:03 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*premier;
	t_list	*new;

	if (!f || !del || !lst)
		return (NULL);
	premier = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (premier)
			{
				new = premier->next;
				del(premier->content);
				free(premier);
				premier = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&premier, new);
		lst = lst->next;
	}
	return (premier);
}
