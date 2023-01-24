/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:36:15 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 17:43:51 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL

void	ft_lstadd_front(t_lst **plst, t_lst *new)
{
	if (*plst != NULL)
		ft_lstadd_back(&new, *plst);
	*plst = new;
}
