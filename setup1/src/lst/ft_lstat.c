/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:16:12 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 17:31:06 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL

t_lst	*ft_lstat(t_lst *lst, int idx)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (i == idx)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
