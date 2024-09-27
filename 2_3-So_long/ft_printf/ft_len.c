/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:38:10 by terussar          #+#    #+#             */
/*   Updated: 2023/03/01 19:04:00 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(long nb)
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

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i += 1;
	}
	return (i);
}

int	ft_lenhexa(unsigned long nb)
{
	int	cpt;

	cpt = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		cpt++;
	}
	return (cpt);
}

//int main()
//{
//	ft_lenhexa
//}