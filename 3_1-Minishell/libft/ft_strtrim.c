/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:36:47 by terussar          #+#    #+#             */
/*   Updated: 2022/11/28 15:25:52 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	isinside(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		l;
	char	*dest;

	i = 0;
	l = 0;
	j = ft_strlen(s1);
	while (s1[i] && isinside(set, s1[i]))
		i++;
	while (j > i && isinside(set, s1[j - 1]))
		j--;
	dest = malloc(sizeof(const char) * (j - i + 1));
	if (!dest)
		return (NULL);
	while (i < j)
	{
		dest[l++] = s1[i++];
	}
	dest[l] = '\0';
	return (dest);
}

// int main()
// {
// 	char const *s1 = "lorem ipsum dolor sit amet"; 
// 	char const *set = "l ";
// 	printf("%s", ft_strtrim(s1, set));
// }
