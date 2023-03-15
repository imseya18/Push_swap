/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:42:22 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/15 18:00:33 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_if_sort(t_list *start_a)
{
	if (start_a == NULL)
		return (1);
	while (start_a->next)
	{
		if (start_a->rank > start_a->next->rank)
			return (0);
		start_a = start_a->next;
	}
	return (1);
}

int	ft_check_size(int nbr)
{
	int	i;

	i = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_check_nbr(int nbr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		nbr = nbr / 10;
		i++;
	}
	return (nbr % 10);
}
