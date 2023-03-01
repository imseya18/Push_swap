/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:13:17 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/01 17:02:36 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_list **start_a)
{
	t_list	*second_m;
	t_list	*first_m;
	t_list	*third_m;

	if(*start_a == NULL)
		return (0);
	first_m = *start_a;
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
	*start_a = second_m;
	return (1);
}
