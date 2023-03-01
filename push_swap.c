/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:04:32 by mmorue            #+#    #+#             */
/*   Updated: 2023/02/28 18:30:36 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_a_stack(t_list **start_a, int a)
{
	t_list	*new;

	new = ft_lstnew(a);
	if (new == 0)
	{
		ftm_free_all();
		return (0);
	}
	ft_lstadd_back(start_a, new);
	return (1);
}

int	argv_checker(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	read_list(t_list *start_a)
{
	t_list	*temp;

	temp = ft_lstlast(start_a);
	while (temp)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->last;
	}
}

int	check_n_create(t_list **start_a, char *argv)
{
	if (argv_checker(argv) == 0)
	{
		ftm_free_all();
		return (0);
	}
	if (create_a_stack(start_a, ft_atoi(argv)) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*start_a;
	t_list	*start_b;

	start_a = 0;
	start_b = 0;
	i = 0;
	if (argc < 2)
		return (0);
	else
		while (++i < argc)
			check_n_create(&start_a, argv[i]);
	read_list(start_a);
}
