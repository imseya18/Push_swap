/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seya <seya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:04:32 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/15 01:55:03 by seya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_a_stack(t_list **start_a, int a)
{
	t_list	*new;
	t_list	*temp;

	temp = *start_a;
	new = ft_lstnew(a);
	if (new == 0)
		return (0);
	while (temp)
	{
		if (temp->content == a)
			return (0);
		temp = temp->next;
	}
	ft_lstadd_back(start_a, new);
	return (1);
}

int	argv_checker(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '-' && argv[1] == 0)
		return (0);
	while (argv[i])
	{
		if (i == 0 && argv[i] == '-')
			i++;
		if ((argv[i] < '0' || argv[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_int_checker(long long a)
{
	if (a > 2147483647)
		return (0);
	if (a < -2147483648)
		return (0);
	return (1);
}

int	check_n_create(t_list **start_a, char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv_checker(argv[i]) == 0)
			return (0);
		if (ft_int_checker(ft_atoi(argv[i])) == 0)
			return (0);
		if (create_a_stack(start_a, ft_atoi(argv[i])) == 0)
			return (0);
	}
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
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
			if (check_n_create(&start_a, ft_split(argv[i], ' ')) == 0)
				ft_error();
	ft_fill_tab(start_a);
	read_list(start_a, start_b);
	//printf("\n\033[0;32m////--- AFTER ---\\\\\\\\ \n\n");
	ft_radix_sort(&start_a, &start_b);
	read_list(start_a, start_b);
	ftm_free_all();
	exit (1);
}
