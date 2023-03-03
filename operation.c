/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:13:17 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/03 15:50:56 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa_pb(t_list **main, t_list **target)
{
	t_list	*first_m;

	if (*main == NULL)
		return (0);
	first_m = *main;
	if (first_m->next)
	{
		first_m->next->last = NULL;
		*main = first_m->next;
	}
	else
		*main = NULL;
	ft_lstadd_front(target, first_m);
	return (0);
}

int	ft_sa_sb(t_list **stack)
{
	t_list	*first_m;
	t_list	*second_m;
	t_list	*third_m;

	if (*stack == NULL)
		return (0);
	first_m = *stack;
	if (first_m->next == NULL)
		return (0);
	second_m = first_m->next;
	third_m = second_m->next;
	first_m->last = second_m;
	second_m->next = first_m;
	second_m->last = NULL;
	if (third_m)
		third_m->last = first_m;
	first_m->next = third_m;
	*stack = second_m;
	return (1);
}

int	ft_ra_rb(t_list **stack)
{
	t_list	*first_m;
	t_list	*last_m;

	if (*stack == NULL)
		return (0);
	first_m = *stack;
	if (first_m->next == NULL)
		return (0);
	last_m = ft_lstlast(*stack);
	if (last_m->last->last)
	{
		*stack = first_m->next;
		first_m->next->last = NULL;
		first_m->next = NULL;
		first_m->last = last_m;
		last_m->next = first_m;
	}
	else
		ft_sa_sb(stack);
	return (1);
}

int	ft_rra_rrb(t_list **stack)
{
	t_list	*first_m;
	t_list	*last_m;

	if (*stack == NULL)
		return (0);
	first_m = *stack;
	if (first_m->next == NULL)
		return (0);
	last_m = ft_lstlast(*stack);
	if (last_m->last->last)
	{
		*stack = last_m;
		last_m->last->next = NULL;
		last_m->last = NULL;
		last_m->next = first_m;
		first_m->last = last_m;
	}
	else
		ft_sa_sb(stack);
	return (1);
}
