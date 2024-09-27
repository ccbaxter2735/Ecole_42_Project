/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:00:09 by terussar          #+#    #+#             */
/*   Updated: 2022/11/29 17:09:16 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (size_t)ft_strlen(s))
	{
		dest = ft_calloc(1, sizeof(char));
		if (!dest)
			return (NULL);
		return (dest);
	}
	else
	{
		if (start + len > (size_t)ft_strlen(s))
			len = ft_strlen(s) - start;
		dest = ft_calloc(len + 1, sizeof(char));
		if (!dest)
			return (NULL);
		i = 0;
		while (++i - 1 < len)
			dest[i - 1] = s[start + i - 1];
		return (dest);
	}
}

// int main()
// {
// 	printf("%s\n", ft_substr("tripouille", 1, 1));
// }