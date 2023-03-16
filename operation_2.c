/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:52:08 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/16 14:24:01 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
	return (0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	ftm_free_all();
	exit (0);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa_sb(stack_a, 0);
	ft_sa_sb(stack_b, 1);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
	{
	ft_ra_rb(stack_a, 0);
	ft_ra_rb(stack_b, 1);
}

void	ft_rrr(t_list**stack_a, t_list **stack_b)
{
	ft_rra_rrb(stack_a, 0);
	ft_rra_rrb(stack_b, 1);
}
