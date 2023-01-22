/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:48:03 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 19:16:37 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_string.h"

#include <stdbool.h>//bool
#include <stddef.h>//NULL
#include <limits.h>//LONG_MAX, LONG_MIN

static bool	ft_isdigit(char c);
static char	*ft_strchr(char const *str, char c);
static int	ft_strspn(char const *str, char const *accept);

int	ft_atoi(char const *nptr)
{
	long	n;
	long	sign;

	nptr += ft_strspn(nptr, " \f\n\r\t\v");
	sign = 1;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	n = 0;
	while (ft_isdigit(*nptr))
	{
		if (n >= (LONG_MAX - (*nptr -'0')) / 10)
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			return ((int)LONG_MIN);
		}
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int) sign * n);
}

static bool	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

static int	ft_strspn(char const *str, char const *accept)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ft_strchr((char*)accept, str[i]) != NULL)
		i++;
	return (i);
}

static char	*ft_strchr(char const *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char*)str);
		str++;
	}
	return (NULL);
}
