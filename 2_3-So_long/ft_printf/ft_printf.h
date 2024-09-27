/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:14:35 by terussar          #+#    #+#             */
/*   Updated: 2023/03/01 19:04:20 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <assert.h>
# include <stdarg.h>
# include <limits.h>

int		ft_putchar2_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
int		ft_putstr2_fd(char *s, int fd);
void	ft_putnbr_unsigned_fd(unsigned int nb, int fd);
int		ft_puthexa(unsigned long nb);
int		ft_puthexa_maj(unsigned long nb);
int		print_putchar(char c);
int		print_putstr(va_list parametre);
int		print_putnbr(va_list parametre);
int		print_puthexa(va_list parametre);
int		print_puthexa_maj(va_list parametre);
int		print_putpointer(va_list parametre);
int		print_put_unsignednbr(va_list parametre);
int		check_letter(char c);
int		len(long nb);
int		ft_strlen2(const char *str);
int		ft_lenhexa(unsigned long nb);
int		ft_printf(const char *arg, ...);

#endif
