/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:44:40 by terussar          #+#    #+#             */
/*   Updated: 2022/11/30 13:49:25 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			count++;
		}
		return (count);
	}
	return (0);
}

// int main()
// {
// t_list *jojo;
// t_list *titi;
// int a;

// jojo = ft_lstnew("salut");
// titi = ft_lstnew("ca va ?");

// jojo->next = titi;
// a = ft_lstsize(jojo);
// printf("%d", a);
// }