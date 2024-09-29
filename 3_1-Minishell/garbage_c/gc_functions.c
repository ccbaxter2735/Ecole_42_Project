/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:29:45 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/08 15:41:05 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK: strdup with gc_malloc info needs status->info[0] and index->info[1]
// and n number of characters to copy
char	*ft_strdup_gc(const char *src, t_vars *vars, int info[2], int n)
{
	int		i;
	char	*dest;
	size_t	l;

	if (!src || !n)
		return (NULL);
	l = ft_strlen(src);
	dest = gc_malloc((l + 1) * sizeof(char), vars, info[0], info[1]);
	if (!dest)
		return (ft_error_parse(malloc_err, vars->list_gc, 1), NULL);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// MARK: info needs status->info[0] and index->info[1]
char	*ft_strjoin_gc(char *s1, char *s2, t_vars *vars, int info[2])
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	ft_init_vars(&len, &i, &j, NULL);
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	dest = gc_malloc(sizeof(char) * (len + 1), vars, info[0], info[1]);
	if (!dest)
		return (ft_error_parse(malloc_err, vars->list_gc, 1), NULL);
	while (s1 && s1[++i])
		dest[i] = s1[i];
	while (s2 && s2[j] && i < len)
	{
		dest[i++] = s2[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa_gc(int nb, t_vars *vars, int info[2])
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	str = (char *)gc_malloc(sizeof(i + 1), vars, info[0], info[1]);
	if (!str)
		return (ft_error_parse(malloc_err, vars->list_gc, 1), NULL);
	str[i] = '\0';
	if (n == 0)
	{
		str[0] = '0';
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--i] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
