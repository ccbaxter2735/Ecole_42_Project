/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:08:56 by terussar          #+#    #+#             */
/*   Updated: 2022/11/28 14:31:57 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= -2 && c >= -128)
	{
		return (256 + c);
	}
	else if (c >= 65 && c <= 90)
	{
		return (c + 32);
	}
	else
	{
		return (c);
	}
}

// int main()
// {
// 	int c = -340;
// 	int i;
// 	while (c <= 100)
// 	{
// 		i = ft_tolower(c);
// 		printf("%d \n%d \n%d\n\n", c, i, tolower(c));
// 		c++;
// 	}
// }
