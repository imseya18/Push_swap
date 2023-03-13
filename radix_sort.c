/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:51:17 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/13 17:32:16 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	sort_push_to_b(t_list **start_a, t_list **start_b)
{
	int size;
	int i;
	int n;

	n = 0;
	while (*start_a != NULL)
	{
		size = ft_lstsize(*start_a);
		i = 0;
		while (i < size)
		{
			if(ft_check_nbr((*start_a)->rank, 0) == n)
				ft_pa_pb(start_a, start_b, 0);
			else
				ft_ra_rb(start_a, 0);
			i++;
		}
		n++;
	}
}
void	sort_push_to_a(t_list **start_a, t_list **start_b)
{
	int size;
	int i;
	int n;

	n = 0;
	while (*start_a != NULL)
	{
		size = ft_lstsize(*start_a);
		i = 0;
		while (i < size)
		{
			if(ft_check_nbr((*start_a)->rank, 0) == n)
				ft_pa_pb(start_b, start_a, 1);
			else
				ft_ra_rb(start_a, 1);
			i++;
		}
		n++;
	}
}
void	sort_big_stack(t_list **start_a, t_list **start_b)
{
	//int size;
	//int i;
	//int n;
//
	//n = 0;
//
	//while (*start_a != NULL)
	//{
	//	size = ft_lstsize(*start_a);
	//	i = 0;
	//	while (i < size)
	//	{
	//		if(ft_check_nbr((*start_a)->rank, 0) == n)
	//			ft_pa_pb(start_a, start_b, 0);
	//		else
	//			ft_ra_rb(start_a, 0);
	//		i++;
	//	}
	//	n++;
	//}
	sort_push_to_b(start_a,start_b);
}

void	ft_radix_sort(t_list **start_a, t_list **start_b)
{
	if (ft_lstsize(*start_a) <= 5)
		sort_small_stack(start_a, start_b);
	else
		sort_big_stack(start_a, start_b);
}
