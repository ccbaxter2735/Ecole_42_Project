/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:36:26 by terussar          #+#    #+#             */
/*   Updated: 2022/11/28 14:31:49 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>
// #include <ctype.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= -2 && c >= -128)
	{
		return (256 + c);
	}
	else if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

// int main()
// {
// 	int c = -10030;
// 	int i;
// 	while (c <= 10000)
// 	{
// 		i = ft_toupper(c);
// 		if (i != toupper(c))
// 		{
// 			printf("%d \n%d \n%d\n\n", c, i, toupper(c));
// 		}
// 		c++;
// 	}
// }
