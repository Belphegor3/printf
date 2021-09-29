/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:52:10 by lfchouch          #+#    #+#             */
/*   Updated: 2021/09/29 21:58:48 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int n);
int		ft_putnbr_hex_lower_ll(long long n);
void	ft_putnbr_unsigned_int(int n);
void	ft_putnbr_hex_lower(int n);
void	ft_putnbr_hex_upper(int n);
void	ft_putstr(const char *str);
int		ft_putchar(char c);

#endif
