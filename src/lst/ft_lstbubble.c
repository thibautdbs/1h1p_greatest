/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbubble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:50:13 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 17:57:43 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL

void	ft_lstbubble(t_lst **plst, int content)
{
	int	i;

	i = ft_lstindex(*plst, content);
	if (i == -1)
		return ;
	while (i > 0)
	{
		ft_lstrotate(plst);
		i++;
	}
}
