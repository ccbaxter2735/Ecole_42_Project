/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:33:41 by terussar          #+#    #+#             */
/*   Updated: 2022/11/30 11:24:35 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(str + i) = (char)c;
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char	str[8];

// 	strcpy(str, "0000000");
// 	puts(str);

// 	memset(str, '1', 10);
// 	puts(str);
// 	return (0);
// }
