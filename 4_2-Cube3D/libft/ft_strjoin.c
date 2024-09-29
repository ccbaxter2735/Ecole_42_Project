/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:55:59 by terussar          #+#    #+#             */
/*   Updated: 2022/11/28 14:27:24 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size2;
	int		i;
	int		j;
	char	*dest;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i++] = s2[j];
		j++;
	}
	dest[i] = 0;
	return (dest);
}

// int	main(void)
// {
// 	char const *s1 = "";
// 	char const *s2 = "";
// 	printf("%s", ft_strjoin(s1, s2));
// }
