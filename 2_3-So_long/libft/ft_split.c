/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:41:14 by terussar          #+#    #+#             */
/*   Updated: 2023/03/15 15:32:15 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_separateur(char const *s, char c)
{
	int	i;
	int	word_status;
	int	count;

	i = 0;
	count = 0;
	word_status = 0;
	if (ft_strlen(s) == count)
		return (-1);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
			word_status = 1;
		if (s[i] == c && word_status == 1)
		{
			word_status = 0;
			count++;
		}
		i++;
	}
	if (word_status == 1)
		count++;
	return (count);
}

static void	write_word(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static char	**free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static void	write_split(char **split, char const *s, char c)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (i + j < ft_strlen(s) && s[i + j] != c && s[i + j])
				j++;
			split[size] = malloc((j + 1) * sizeof(char));
			if (!split[size])
				free_split(split);
			write_word(split[size++], s + i, c);
			i += j;
		}
	}
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		size;

	if (!s)
		return (NULL);
	if (*s == '\0')
		size = 0;
	else
		size = nb_separateur(s, c);
	result = malloc((size + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[size] = 0;
	write_split(result, s, c);
	return (result);
}

// int	main()
// {
// 	int		index;
// 	char	**split;
// 	split = ft_split("tripouille  les temps", ' ');
// 	index = 0;
// 	while (split[index])
// 	{
// 		printf("%s\n", split[index]);
// 		free(split[index]);
// 		index++;
// 	}
// 	free(split);
// }
