/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:31:51 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/01 11:01:58 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

char	**free_split_gc(char **split)
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

static void	write_split(char **split, char const *s, t_vars *vars, int info[3])
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == ' ' || (s[i + 1] && s[i] == '+' && s[i + 1] != ' '))
			i++;
		else
		{
			j = 0;
			while (i + j < ft_strlen(s) && s[i + j] != ' ' && s[i + j])
				j++;
			split[size] = gc_malloc((j + 1) * sizeof(char), vars, info[0],
					info[1]);
			if (!split[size])
				free_split_gc(split);
			write_word(split[size++], s + i, ' ');
			i += j;
		}
	}
}

//MARK: info needs status->info[0] and index->info[1] || don't fill info[2]
char	**ft_split_gc(const char *s, char c, t_vars *vars, int info[3])
{
	char	**result;
	int		size;

	if (!s)
		return (NULL);
	if (*s == '\0')
		size = 0;
	else
		size = nb_separateur(s, c);
	result = gc_malloc((size + 1) * sizeof(char *), vars, info[0], info[1]);
	if (!result)
		return (NULL);
	result[size] = 0;
	write_split(result, s, vars, info);
	return (result);
}
