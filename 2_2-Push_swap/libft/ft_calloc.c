/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:21 by terussar          #+#    #+#             */
/*   Updated: 2022/12/01 17:15:03 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	if (size != 0 && nmemb != ((nmemb * size) / size))
		return (NULL);
	else
	{
		str = (void *)malloc(nmemb * size);
		if (!str)
			return (NULL);
		i = 0;
		while (i < nmemb * size)
		{
			str[i] = 0;
			i++;
		}
		return (str);
	}
}

// int main()
// {
// 	char *str = (char *)ft_calloc(30, 1);
// 	write(1, str, 30);

// 	return (0);
// }