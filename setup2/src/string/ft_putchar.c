/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:10:06 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/24 08:10:41 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_string.h"

#include <unistd.h>//write

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
