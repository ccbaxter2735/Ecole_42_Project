/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:38:20 by terussar          #+#    #+#             */
/*   Updated: 2022/11/30 12:23:23 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

// int main()
// {
// t_list *jojo;
// t_list *titi;

// jojo = ft_lstnew("salut");
// titi = ft_lstnew("ca va ?");

// jojo->next = titi;
// while (jojo)
// {
// 	printf("%s", (char *)jojo->content);
// 	jojo = jojo->next;
// }
// }