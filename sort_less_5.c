/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:06:39 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/15 18:17:40 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_pos(t_list *start_a, int rank)
{
	int	i;

	i = 0;
	if (start_a == NULL || ft_lstsize(start_a) <= 1)
		return (0);
	while (start_a->rank != rank && start_a)
	{
		i++;
		start_a = start_a->next;
	}
	return (i);
}

void	ft_medium_rotate(t_list **start_a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_ra_rb(start_a, 0);
		i++;
	}
}

void	ft_medium_r_rotate(t_list **start_a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_rra_rrb(start_a, 0);
		i++;
	}
}

void	sort_medium_stack(t_list **start_a, t_list **start_b)
{
	int	i;
	int	size;

	size = ft_lstsize(*start_a);
	i = 0;
	while (i < size - 3)
	{
		if (check_pos(*start_a, i) < ft_lstsize(*start_a) / 2
			|| (check_pos(*start_a, i) == ft_lstsize(*start_a) / 2
				&& ft_lstsize(*start_a) % 2 != 0))
			ft_medium_rotate(start_a, check_pos(*start_a, i));
		else
			ft_medium_r_rotate(start_a, ft_lstsize(*start_a)
				- check_pos(*start_a, i));
		ft_pa_pb(start_a, start_b, 0);
		i++;
	}
	sort_small_stack(start_a);
	while (*start_b)
		ft_pa_pb(start_b, start_a, 1);
}
