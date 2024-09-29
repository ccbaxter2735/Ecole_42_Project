/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_wsp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:53:39 by pduhamel          #+#    #+#             */
/*   Updated: 2023/10/01 11:34:21 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	word_in(char const *s)
{
	int		nb;
	size_t	i;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (is_wsp(s[i]) && s[i])
			i++;
		while (!is_wsp(s[i]) && s[i])
			i++;
		if (!is_wsp(s[i - 1]))
			nb++;
		while (is_wsp(s[i]) && s[i])
			i++;
	}
	return (nb);
}

static void	ft_free_split(int i, char **tstr)
{
	while (i >= 0)
	{
		free(tstr[i]);
		i--;
	}
	free(tstr);
}

static char	*ft_cpy(char const *s, int n, t_vars *vars, int info[2])
{
	char	*s1;
	int		i;

	i = 0;
	s1 = gc_malloc(sizeof(char) * (n + 1), vars, info[0], info[1]);
	if (s1 == NULL)
		return (NULL);
	while (i < n && *s)
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static const char	*go_on(const char *s)
{
	while (is_wsp(*s) && *s)
		s++;
	return (s);
}

char	**ft_split_wsp(char const *s, int in[2], t_vars *vars)
{
	char	**tstr;
	int		n;
	int		i;

	i = 0;
	tstr = gc_malloc(sizeof(char *) * (word_in(s) + 1), vars, in[0], in[1]);
	if (tstr == NULL)
		return (NULL);
	while (*s && word_in(s) != 0)
	{
		n = 0;
		s = go_on(s);
		while (!is_wsp(*s) && *s && s++)
			n++;
		tstr[i] = ft_cpy((s - n), n, vars, in);
		if (tstr[i] == NULL)
		{
			ft_free_split(i, tstr);
			return (NULL);
		}
		if (n != 0)
			i++;
	}
	tstr[i] = NULL;
	return (tstr);
}
