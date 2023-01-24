/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:30:14 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/24 07:58:56 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_string.h"

#include <unistd.h>//write

static void	ft_putchar(char c);

void	ft_putnbr(int n)
{
	int	leading_digits;
	int	last_digit;

	leading_digits = n / 10;
	last_digit = n % 10;
	if (n < 0)
	{
		ft_putchar('-');
		leading_digits *= -1;
		last_digit += -1;
	}
	if (leading_digits > 0)
		ft_putnbr(leading_digits);
	ft_putchar(last_digit + '0');
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}
