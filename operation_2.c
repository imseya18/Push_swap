/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:52:08 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/02 18:04:55 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa_sb(stack_a);
	ft_sa_sb(stack_b);
}
void ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra_rb(stack_a);
	ft_ra_rb(stack_b);
}
void ft_rrr (t_list**stack_a, t_list **stack_b)
{
	ft_rra_rrb(stack_a);
	ft_rra_rrb(stack_b);
}