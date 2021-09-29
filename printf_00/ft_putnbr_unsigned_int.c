/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 06:45:59 by lfchouch          #+#    #+#             */
/*   Updated: 2021/09/29 18:37:24 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_unsigned_int(int n)
{
	long	x;

	x = n;
	if (n < 0)
		x = (2 * 2147483648) + n;
	if (x >= 10)
	{
		ft_putnbr_unsigned_int(x / 10);
		ft_putnbr_unsigned_int(x % 10);
	}
	else
		if (x <= 9)
			ft_putchar(x + '0');
}
