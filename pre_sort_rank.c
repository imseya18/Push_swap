/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_rank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:16:14 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/13 17:29:54 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*ft_quicksort(int *tab, int end, int start, int size)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = start;
	j = start;
	if (start < end && j < size)
	{
		while (j < end)
		{
			if (tab[j] < tab[end])
			{
				ft_swap(&tab[i], &tab[j]);
				i++;
			}
			j++;
		}
		ft_swap(&tab[i], &tab[end]);
		ft_quicksort(tab, i - 1, start, size);
		ft_quicksort(tab, end, i + 1, size);
	}
	return (tab);
}

void	ft_assign_rank(t_list *start_a, int *tab)
{
	int	i;

	i = 0;
	while (start_a)
	{
		while (tab[i] != start_a->content)
			i++;
		start_a->rank = i;
		i = 0;
		start_a = start_a->next;
	}
}

void	ft_fill_tab(t_list *start_a)
{
	int		i;
	int		*tab;
	t_list	*temp;

	i = 0;
	tab = ftm_malloc(ft_lstsize(start_a) * sizeof(int));
	temp = start_a;
	while (temp)
	{
		tab[i] = temp->content;
		i++;
		temp = temp->next;
	}
	tab = ft_quicksort(tab, i - 1, 0, i);
	ft_assign_rank(start_a, tab);
}
