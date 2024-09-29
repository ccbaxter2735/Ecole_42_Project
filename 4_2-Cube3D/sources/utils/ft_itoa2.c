/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:51:12 by khle              #+#    #+#             */
/*   Updated: 2024/01/19 16:35:01 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_get_neg(int n)
{
	if (n < 0)
	n = -n;
	return (n);
}

int	ft_get_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa2(long long n)
{
	int		i;
	char	*str;

	i = ft_get_len(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[i] = 0;
	while (n != 0)
	{
		i--;
		str[i] = ft_get_neg(n % 10) + 48;
		n = n / 10;
	}
	return (str);
}

int	ft_free_tab(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		free(str[i]);
	free(str);
	return (0);
}

char	*copy_new(char *str, int *i)
{
	char	*new_str;
	int		j;

	j = 0;
	new_str = malloc(sizeof(char) * (*i + 1));
	if (!new_str)
		return (0);
	while (str && str[j] && j < *i)
	{
		new_str[j] = str[j];
		j++;
	}
	new_str[j] = 0;
	free(str);
	return (new_str);
}
