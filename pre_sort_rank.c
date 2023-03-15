/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_rank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:16:14 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/15 16:41:17 by mmorue           ###   ########.fr       */
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

int	*int_to_binary(unsigned int n)
{
	int	*binary;
	int	i;

	i = -1;
	binary = ftm_malloc(32 * sizeof(int));
	while (++i < 32)
		binary[i] = 0;
	i = 31;
	while (n > 0)
	{
		binary[i] += (n % 2);
		n /= 2;
		i--;
	}
	return (binary);
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
		start_a->binary = int_to_binary(start_a->rank);
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
