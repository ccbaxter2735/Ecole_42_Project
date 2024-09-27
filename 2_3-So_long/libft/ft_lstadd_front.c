/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:27:14 by terussar          #+#    #+#             */
/*   Updated: 2022/11/30 13:42:06 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
		{
			new->next = *lst;
		}
		*lst = new;
	}
}

// int main()
// {
// t_list *tab;
// t_list *jojo;
// t_list *titi;

// tab = ft_lstnew("salut");
// titi = ft_lstnew("ca va ?");
// jojo = ft_lstnew("coucou ");
// tab->next = titi;
// ft_lstadd_front(&tab, jojo);
// while (tab)
// {
// 	printf("%s", (char *)tab->content);
// 	tab = tab->next;
// }
// }
