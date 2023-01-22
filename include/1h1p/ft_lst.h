/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:14:20 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/22 18:26:05 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef struct s_lst
{
	int				content;
	struct s_lst	*next;
}	t_lst;

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

t_lst	*ft_lstcreate(int content);
void	ft_lstdestroy(t_lst **plst);

void	ft_lstadd_front(t_lst **plst, t_lst *new);
void	ft_lstadd_back(t_lst **plst, t_lst *new);

t_lst	*ft_lstpop_front(t_lst **plst);
t_lst	*ft_lstpop_back(t_lst **plst);

t_lst	*ft_lstat(t_lst *lst, int idx);
t_lst	*ft_lstlast(t_lst *lst);

int		ft_lstindex(t_lst *lst, int content);
int		ft_lstmin(t_lst *lst);

void	ft_lstrotate(t_lst **plst);
void	ft_lstbubble(t_lst **plst, int content);

#endif //FT_LST_H
