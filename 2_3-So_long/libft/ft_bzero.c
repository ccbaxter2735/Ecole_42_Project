/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:33:27 by terussar          #+#    #+#             */
/*   Updated: 2022/12/04 15:38:48 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(str + i) = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char	str[8];

// 	strcpy(str, "1111111");
// 	puts(str);

// 	ft_bzero(str,1);
// 	puts(str);
// 	return (0);
// }