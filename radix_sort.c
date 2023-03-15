/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:51:17 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/15 18:07:42 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_list **a)
{
	if (ft_lstsize(*a) == 2)
		ft_sa_sb(a, 0);
	if (ft_check_if_sort(*a) == 1)
		return ;
	if ((*a)->rank > (*a)->next->rank && (*a)->next->rank
		< (*a)->next->next->rank && (*a)->rank < (*a)->next->next->rank)
		ft_sa_sb(a, 0);
	else if ((*a)->rank > (*a)->next->rank && (*a)->next->rank
		> (*a)->next->next->rank)
	{
		ft_sa_sb(a, 0);
		ft_rra_rrb(a, 0);
	}
	else if ((*a)->rank > (*a)->next->rank
		&& (*a)->next->rank < (*a)->next->next->rank)
		ft_ra_rb(a, 0);
	else if ((*a)->rank < (*a)->next->rank && (*a)->next->rank
		> (*a)->next->next->rank && (*a)->rank < (*a)->next->next->rank)
	{
		ft_sa_sb(a, 0);
		ft_ra_rb(a, 0);
	}
	else if ((*a)->rank < (*a)->next->rank
		&& (*a)->next->rank > (*a)->next->next->rank)
		ft_rra_rrb(a, 0);
}

void	sort_push_to_a(t_list **start_b, t_list **start_a, int div, int flag)
{
	int	size;
	int	i;
	int	n;

	n = 9;
	while (n >= 0)
	{
		size = ft_lstsize(*start_b);
		i = 0;
		while (i < size)
		{
			if (ft_check_nbr((*start_b)->rank, div) == n)
				ft_pa_pb(start_b, start_a, flag);
			else
				ft_ra_rb(start_b, flag);
			i++;
		}
		n--;
	}
}

void	sort_push_to_b(t_list **start_a, t_list **start_b, int div, int flag)
{
	int	size;
	int	i;

	size = ft_lstsize(*start_a);
	i = 0;
	while (i < size)
	{
		if (((*start_a)->binary[div]) == 0)
			ft_pa_pb(start_a, start_b, flag);
		else
			ft_ra_rb(start_a, flag);
		i++;
	}
}

void	sort_big_stack_binary(t_list **start_a, t_list **start_b)
{
	int	div;
	int	size;

	size = ft_lstsize(*start_a);
	if (size <= 100)
		size = 25;
	else if (size <= 500)
		size = 23;
	else
		size = 0;
	div = 31;
	while (div >= size)
	{
		sort_push_to_b(start_a, start_b, div, 0);
		while (*start_b != NULL)
			ft_pa_pb(start_b, start_a, 1);
		div--;
	}
}

void	ft_radix_sort(t_list **start_a, t_list **start_b)
{
	if (ft_lstsize(*start_a) <= 3)
		sort_small_stack(start_a);
	else if (ft_lstsize(*start_a) <= 10)
		sort_medium_stack(start_a, start_b);
	else
		sort_big_stack_binary(start_a, start_b);
}
