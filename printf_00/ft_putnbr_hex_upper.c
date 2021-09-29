/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 07:34:56 by lfchouch          #+#    #+#             */
/*   Updated: 2021/09/29 18:32:13 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_hex_upper(int n)
{
	long	x;

	x = n;
	if (n < 0)
		x = (2 * 2147483648) + n;
	if (x >= 16)
	{
		ft_putnbr_hex_upper(x / 16);
		ft_putnbr_hex_upper(x % 16);
	}
	else
	{
		if (x <= 9)
			ft_putchar(x + '0');
		if (x > 9 && x <= 15)
		{
			x = x - 10;
			ft_putchar(x + 'A');
		}
	}
}
