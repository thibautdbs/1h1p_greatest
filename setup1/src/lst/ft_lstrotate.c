/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:48:10 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 18:02:53 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL

void	ft_lstrotate(t_lst **plst)
{
	if (*plst == NULL)
		return ;
	ft_lstadd_back(plst, ft_lstpop_front(plst));
}
