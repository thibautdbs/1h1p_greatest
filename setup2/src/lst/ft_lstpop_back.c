/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:55:09 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 17:32:25 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL

t_lst	*ft_lstpop_back(t_lst **plst)
{
	t_lst	*last;

	if (*plst == NULL)
		return (NULL);
	while ((*plst)->next != NULL)
		plst = &(*plst)->next;
	last = *plst;
	*plst = NULL;
	return (last);
}
