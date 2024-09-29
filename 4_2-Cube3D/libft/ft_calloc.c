/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:21 by terussar          #+#    #+#             */
/*   Updated: 2024/01/19 16:39:10 by khle             ###   ########.fr       */
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
