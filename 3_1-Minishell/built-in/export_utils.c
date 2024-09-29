/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:02:58 by terussar          #+#    #+#             */
/*   Updated: 2023/11/08 18:02:37 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	find_quote(char *s, int *cpt)
{
	int		i;
	char	c;

	i = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			c = s[i];
			*cpt += 1;
			i++;
			while (s[i] && s[i] != c)
				i++;
			if (s[i] && s[i] == c)
				*cpt += 1;
		}
		if (s[i])
			i++;
	}
}

char	*erase_annexe(char *dest, char *s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			c = s[i];
			i++;
			while (s[i] && s[i] != c)
				dest[++j] = s[i++];
			if (s[i] && !s[i + 1])
				break ;
			if (s[i] == c)
				continue ;
		}
		if (s[i])
			dest[++j] = s[i++];
	}
	return (dest[++j] = 0, dest);
}

char	*erase_quote(char *source)
{
	char	*dest;
	int		nb_quote;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nb_quote = 0;
	find_quote(source, &nb_quote);
	dest = malloc(sizeof(char) * (ft_strlen(source) - nb_quote + 1));
	if (!dest)
		return (NULL);
	dest = erase_annexe(dest, source);
	return (dest);
}

int	check_equal(char *str)
{
	int	i;
	int	cpt;

	i = -1;
	cpt = 0;
	while (str[++i])
	{
		if (str[i] == '=')
			cpt++;
	}
	if (cpt != 1)
		return (msg_error("minishell: export: one '=' required: ", str), 1);
	return (0);
}

int	exp_cdt(char *str)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	if (check_equal(str))
		return (1);
	if (ft_isalpha(str[0]) == 0 && str[0] != '_')
		return (msg_error("minishell: export: not a valid variable: ", str), 1);
	while (str[i] && str[i] != '=')
	{
		if (ft_isalpha(str[i]) == 1)
			cpt++;
		if (str[i] == ' ' || (ft_isalpha(str[i]) == 0
				&& ft_isdigit(str[i]) == 0 && i != 0))
			return (msg_error("minishell: export: not a valid variable: ", str)
				, 1);
		i++;
	}
	if (cpt == 0)
		return (msg_error("minishell: export: not a valid variable: ", str), 1);
	return (0);
}
