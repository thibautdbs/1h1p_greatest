/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:07:54 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/24 08:04:34 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL
#include <stdlib.h>//calloc

t_lst	*ft_lstcreate(int content)
{
	t_lst	*node;

	node = calloc(1, sizeof(t_lst));
	if (node == NULL)
		return (node);
	node->content = content;
	node->next = NULL;
	return (node);
}
