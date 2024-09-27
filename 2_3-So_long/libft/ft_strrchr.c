/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:33:19 by terussar          #+#    #+#             */
/*   Updated: 2022/11/28 14:31:34 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (char)(c))
		{
			return ((char *)(s + i));
		}
		i--;
	}
	return (NULL);
}

// int	main()
// {
// 	int c = 'b';
// 	char *i;
// 	const char str[] = "bonjour";
// 	i = ft_strrchr(str, c);
// 	printf("%c \n%s \n%s\n\n", c, i, strrchr(str, c));
// }