/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:57:57 by terussar          #+#    #+#             */
/*   Updated: 2022/11/30 12:30:23 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// int main()
// {
// t_list *jojo;
// t_list *titi;
// t_list *a;

// jojo = ft_lstnew("salut");
// titi = ft_lstnew("ca va ?");

// jojo->next = titi;
// a = ft_lstlast(jojo);
// printf("%s", (char *)a->content);
// }