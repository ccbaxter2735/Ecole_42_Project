/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:51:39 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/03 17:08:04 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	nb_separateur(char const *s, char c, t_vars *vars)
{
	int	i;
	int	word_status;
	int	count;
	int	quote;

	ft_init_vars(&count, &i, &quote, NULL);
	word_status = 0;
	if (ft_strlen(s) == count)
		return (-1);
	while (s[++i] == c)
		ft_split_check(s + i, c, vars, &quote);
	while (s[i] && !ft_split_check(s + i, c, vars, &quote))
	{
		if (s[i] != c && i != (ft_strlen(s) - 1))
			word_status = 1;
		if (s[i] == c && word_status == 1 && !quote)
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

static void	write_word(char *dest, const char *src, int *info, t_vars *vars)
{
	int	i;

	i = 0;
	if (ft_empty(src, info[2], vars))
	{
		dest[i] = '\0';
		return ;
	}
	while (i < info[6] && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void	write_split(char **split, char const *s, t_vars *vars, int info[7])
{
	int	i;

	i = 0;
	ft_init_vars(&(info[3]), NULL, &(info[4]), NULL);
	while (s[i] && info[4] <= info[5])
	{
		info[6] = 0;
		while (i + info[6] < ft_strlen(s) && ((s[i + info[6]] != info[2]
					&& !quotes(&info[3], s[i + info[6]])) || info[3]))
			info[6]++;
		split[info[4]] = gc_malloc((info[6] + 1) * sizeof(char), vars, info[0],
				info[1]);
		if (!split[info[4]])
			free_split(split);
		write_word(split[info[4]++], s + i, info, vars);
		if (s[i + info[6]] == info[2] && ft_strlen(s) > (i + info[6] + 1))
			i += info[6] + 1;
		else
			i += info[6];
	}
}

// Mark: for parsing only | it's make check of the input
char	**ft_split_parse(const char *s, char c, t_vars *vars, int info[7])
{
	char	**result;
	int		size;

	if (!s)
		return (NULL);
	info[5] = ft_end_split(s, vars);
	if (*s == '\0')
		size = 0;
	else
		size = nb_separateur(s, c, vars);
	if (!size && !(*s == '\0'))
		size++;
	info[5] = size;
	info[2] = c;
	info[3] = 0;
	result = gc_malloc((size + 2) * sizeof(char *), vars, info[0], info[1]);
	if (!result)
		return (NULL);
	result[(size + 1)] = NULL;
	result[size] = NULL;
	write_split(result, s, vars, info);
	return (result);
}
