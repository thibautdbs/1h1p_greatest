/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate_from_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:10:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/27 10:13:49 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <stddef.h>//NULL

#include "1h1p/ft_string.h"//ft_atoi

t_lst	*ft_lstcreate_from_arr(char **arr, int size)
{
	int		i;
	t_lst	*lst;

	lst = NULL;
	i = 1;
	while (i < size)
	{
		ft_lstadd_back(&lst, ft_lstcreate(ft_atoi(arr[i])));
		i++;
	}
	return (lst);
}
