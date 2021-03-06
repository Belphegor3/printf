/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:50:37 by lfchouch          #+#    #+#             */
/*   Updated: 2021/09/29 18:43:31 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	static int	count = 0;

	if (c == (char ) NULL)
		return (count);
	count++;
	write(1, &c, 1);
	return (count);
}
