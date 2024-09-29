/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:08:23 by terussar          #+#    #+#             */
/*   Updated: 2023/11/08 16:40:08 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK : find if there is some other word in string
int	if_other_word(char *s, int j)
{
	if (!s || j >= ft_strlen(s) || !(*s))
		return (0);
	while (s[j])
	{
		if (s[j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

// MARK : change character \n => n
int	change_backslash_keys(char c)
{
	char	*change_letter;
	int		i;

	i = 0;
	change_letter = "abefnrtv";
	while (i < 9)
	{
		if (c == change_letter[i])
			return (1);
		i++;
	}
	return (0);
}

// MARK : annexe find and write word with quotes
int	write_word_annexe2(char *s, int i, t_vars *vars)
{
	int	j;

	j = i + 1;
	while (s[j] && s[j] != s[i])
		j++;
	if (j < ft_strlen(s))
	{
		while (++i < j)
		{
			if (write_err(&s[i], 0, vars) < 0)
				return (-42);
		}
		i++;
	}
	return (i);
}

// MARK : annexe find and write word if no quotes
int	write_word_annexe1(char *s, int i, t_vars *vars)
{
	while (s[i] && s[i] != ' ' && s[i] != 34 && s[i] != 39)
	{
		if (s[i] == 92)
		{
			if (change_backslash_keys(s[i + 1]) == 1)
				i++;
		}
		if (write_err(&s[i++], 0, vars) < 0)
			return (-42);
	}
	return (i);
}

int	write_err(char *c, int n, t_vars *vars)
{
	if (write(1, c, 1) < 0)
	{
		if (n == 1)
			vars->ret_val = 125;
		else
			vars->ret_val = 1;
		return (-42);
	}
	return (1);
}
