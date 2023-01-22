/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:51:30 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 17:32:48 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL

t_lst	*ft_lstpop_front(t_lst **plst)
{
	t_lst	*first;

	if (*plst == NULL)
		return (NULL);
	first = *plst;
	*plst = first->next;
	first->next = NULL;
	return (first);
}
