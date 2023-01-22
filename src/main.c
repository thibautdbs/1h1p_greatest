/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:12:06 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 19:28:47 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1h1p/ft_lst.h"
#include "1h1p/ft_string.h"

#include <errno.h>//errno
#include <stddef.h>//NULL

int	main(int argc, char **argv)
{
	t_lst	*nbrs;
	int	i;

	nbrs = NULL;
	if (argc < 1)
		return (1);
	errno = 0;
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&nbrs, ft_lstcreate(ft_atoi(argv[i])));
		i++;
	}
	if (errno == 0)
	{
		ft_lstbubble(&nbrs, ft_lstmin(nbrs));
		ft_lstdisplay(nbrs);
	}
	ft_lstdestroy(&nbrs);
	return (errno);
}
