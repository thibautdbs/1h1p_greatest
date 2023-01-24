/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdisplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:01:57 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/24 08:03:35 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL

#include "1h1p/ft_string.h"

void	ft_lstdisplay(t_lst const *lst)
{
	while (lst != NULL)
	{
		ft_putnbr(lst->content);
		lst = lst->next;
	}
}
