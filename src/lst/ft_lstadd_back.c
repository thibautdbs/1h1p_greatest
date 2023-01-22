/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:36:15 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 17:46:35 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL

void	ft_lstadd_back(t_lst **plst, t_lst *new)
{
	while (*plst != NULL)
		plst = &(*plst)->next;
	*plst = new;
}
