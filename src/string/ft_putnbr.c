/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:30:14 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 19:48:22 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_string.h"

void	ft_putnbr(int n)
{
	char	nptr[8];
	int		i;

	ft_bzero(nptr, 8);
	i = 0;
	if (n < 0)
	{
		nptr[0] = '-';
		n = -n;
		i++;
	}
	while (i < 7 && n / 10 > 0)
	{
		nptr[i] = n % 10;
		n = n / 10;
		i++;
	}
	if (n / 10 > 0)
		ft_putnbr(n);
}
