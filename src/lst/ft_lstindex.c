/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:58:33 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 18:01:38 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL

int	ft_lstindex(t_lst *lst, int content)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (lst->content == content)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
