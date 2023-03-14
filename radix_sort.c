/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:51:17 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/14 14:50:20 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int ft_check_size(int nbr)
{
	int i;

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

void	sort_small_stack(t_list **start_a, t_list **start_b)
{
	start_a = NULL;
	start_b = NULL;
}
void	sort_push_to_b(t_list **start_a, t_list **start_b, int div, int flag)
{
	int size;
	int i;
	int n;

	n = 0;
	while (n <= 9)
	{
		size = ft_lstsize(*start_a);
		i = 0;
		while (i < size)
		{
			if(ft_check_nbr((*start_a)->rank, div) == n)
				ft_pa_pb(start_a, start_b, flag);
			else
				ft_ra_rb(start_a, flag);
			i++;
		}
		n++;
	}
}
void	sort_push_to_a(t_list **start_b, t_list **start_a, int div, int flag)
{
	int size;
	int i;
	int n;

	n = 9;
	while (n >= 0)
	{
		size = ft_lstsize(*start_b);
		i = 0;
		while (i < size)
		{
			if(ft_check_nbr((*start_b)->rank, div) == n)
				ft_pa_pb(start_b, start_a, flag);
			else
				ft_ra_rb(start_b, flag);
			i++;
		}
		n--;
	}
}

void	sort_big_stack(t_list **start_a, t_list **start_b, int rank_size)
{
	int div;

	div = 0;
	while(div < rank_size)
	{
		sort_push_to_b(start_a,start_b,div, 0);
		div++;
		sort_push_to_a(start_b,start_a,div, 1);
		div++;
	}
}

void	ft_radix_sort(t_list **start_a, t_list **start_b)
{
	int rank;
	int rank_size;
	rank = ft_lstsize(*start_a) - 1;
	rank_size = ft_check_size(rank);
	if (rank <= 5)
		sort_small_stack(start_a, start_b);
	else
		sort_big_stack(start_a, start_b, rank_size);
}
