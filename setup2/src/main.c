/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:12:06 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/27 11:43:34 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"

#include <errno.h>//errno
#include <stddef.h>//NULL

#include "1h1p/ft_string.h"

int	main(int argc, char **argv)
{
	t_lst	*nbrs;

	if (argc < 1)
		return (1);
	errno = 0;
	nbrs = ft_lstcreate_from_arr(argv + 1, argc - 1);
	if (errno == 0)
	{
		ft_lstbubble(&nbrs, ft_lstmin(nbrs));
		ft_lstdisplay(nbrs);
	}
	ft_lstdestroy(&nbrs);
	return (errno);
}
