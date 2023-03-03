/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:04:32 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/03 15:50:53 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_a_stack(t_list **start_a, int a)
{
	t_list	*new;

	new = ft_lstnew(a);
	if (new == 0)
		return (0);
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

void	read_list(t_list *start_a, t_list *start_b)
{
	t_list	*current = start_a;
	t_list	*current_b = start_b;

	ft_printf("\n\033[0;32m////--- STACK A ---\\\\\\\\ 			\033[0;32m////--- STACK B ---\\\\\\\\\n\n");
    while (current != NULL || current_b != NULL)
    {
		if (current)
        	printf("\033[0;36mMaillon address: \033[0;33m%p\033[0m			", (void *)current);
		if (current == NULL)
			printf("						");
		if (current_b == NULL)
			printf("\n");
		if (current_b != NULL)
			printf("\033[0;36mMaillon address: \033[0;33m%p\033[0m\n", (void *)current_b);
		if (current)
        	printf("\033[0;36mContent: \033[0;35m%d\033[0m					", current->content);
		if (current == NULL)
			printf("						");
		if (current_b == NULL)
			printf("\n");
		if (current_b != NULL)
			printf("\033[0;36mContent: \033[0;35m%d\033[0m\n", current_b->content);
		if (current)
     		printf("\033[0;36mLast address: \033[0;33m%p\033[0m				", (void *)current->last);
		if (current == NULL)
			printf("						");
		if (current_b == NULL)
			printf("\n");
		if (current_b)
			printf("\033[0;36mLast address: \033[0;33m%p\033[0m\n",(void *)current_b->last);
		if (current)
			printf("\033[0;36mNext address: \033[0;33m%p\033[0m				", (void *)current->next);
		if (current == NULL)
			printf("						");
		if (current_b == NULL)
			printf("\n");
		if (current_b)
			printf("\033[0;36mNext address: \033[0;33m%p\033[0m\n", (void *)current_b->next);
		if (current == NULL)
			printf("						");
		printf("\033[0;31m-------\033[0m\n");
		if (current)
			current = current->next;
		if (current_b)
			current_b = current_b->next;
    }
}

int	check_n_create(t_list **start_a, char *argv)
{
	if (argv_checker(argv) == 0)
		return (0);
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
			if (check_n_create(&start_a, argv[i]) == 0)
				ft_error();
	read_list(start_a, start_b);
	ft_printf("\n\033[0;32m////--- AFTER ---\\\\\\\\ \n\n");
	read_list(start_a, start_b);
	ftm_free_all();
	exit (1);
}
