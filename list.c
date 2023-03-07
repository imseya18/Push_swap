/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:35:58 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/07 18:09:11 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = ftm_malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->rank = 0;
	new->next = NULL;
	new->last = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
	new->last = temp;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{	
	t_list	*temp;

	temp = *lst;
	if (new == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	else
	{
		temp->last = new;
		new->next = *lst;
	}
	new->last = NULL;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(lst);
	while (i < size - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}	
	return (i);
}
