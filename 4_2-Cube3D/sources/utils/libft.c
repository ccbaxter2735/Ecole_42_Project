/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:55:40 by khle              #+#    #+#             */
/*   Updated: 2024/01/19 16:32:17 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	*ft_memset2(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char) c;
		i++;
	}
	return (b);
}

int	ft_atoi2(char *str, int *pos)
{
	int	len;
	int	nbr;
	int	j;

	len = 0;
	nbr = 0;
	j = 1;
	while (str && str[*pos] && str[*pos] == ' ')
		*pos += 1;
	while (str && str[*pos] && (str[*pos] >= '0' && str[*pos] <= '9'))
	{
		if (str[*pos - 1] == '-')
			j = -1;
		nbr = nbr * 10 + (str[*pos] - '0');
		*pos += 1;
		len++;
	}
	if (len == 0 || len > 3 || j == -1)
		return (-1);
	return (nbr);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = 0;
	}
	str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	free(s1);
	return (str);
}

char	*ft_strdup2(char *str1)
{
	char	*str2;
	size_t	i;

	i = 0;
	str2 = (char *)malloc(sizeof (*str1) * (ft_strlen(str1) + 1));
	if (!str2)
		return (NULL);
	while (str1[i])
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = 0;
	return (str2);
}

int	check_open_image(char *image)
{
	int	fd;

	fd = open(image, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}
