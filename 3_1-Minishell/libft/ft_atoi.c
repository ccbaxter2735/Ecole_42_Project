/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:50:49 by terussar          #+#    #+#             */
/*   Updated: 2023/04/30 21:37:27 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	total;

	i = 0;
	signe = 1;
	total = 0;
	if (!nptr)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] > 7 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -signe;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		total = total * 10 + (nptr[i] - '0');
		i++;
	}
	return (signe * total);
}

// int main()
// {
// 	const char *x = "0";
// 	printf("%d\n%d", ft_atoi(x), atoi(x));
// }
