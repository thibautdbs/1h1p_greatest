/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdestroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:03:23 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 18:07:01 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL
#include <stdlib.h>//free

void	ft_lstdestroy(t_lst **plst)
{
	while (*plst != NULL)
		free(ft_lstpop_front(plst));
	*plst = NULL;
}
