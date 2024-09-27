/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:07:51 by terussar          #+#    #+#             */
/*   Updated: 2022/11/29 11:15:43 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <bsd/string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0' || !big)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && i + j < len
			&& little[j] && (big[i + j] == little[j]))
		{
			j++;
		}
		if (!little[j])
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

// int	main()
// {
// 	char *empty = (char*)"";
// 	// const char *big = "";
// 	// const char *little = "3";
// 	printf("ft %s\n", ft_strnstr(empty, "", 0));
// 	printf("re %s\n", strnstr(empty, "", 0));
// }
