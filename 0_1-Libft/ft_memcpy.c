/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:51:43 by terussar          #+#    #+#             */
/*   Updated: 2022/11/28 14:29:16 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

//  int main()
//  {
// 	char src[10];
// 	char dest[10];
// 	strcpy(src, "123456789");
// 	strcpy(dest, "000099670");
// 	puts(src);

// 	memcpy(dest, dest + 5, 3);
// 	puts (dest);
//  }