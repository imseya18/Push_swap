/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:04:32 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/07 18:09:01 by mmorue           ###   ########.fr       */
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
        	printf("\033[0;36mrank: \033[0;35m%d\033[0m					", current->rank);
		if (current == NULL)
			printf("						");
		if (current_b == NULL)
			printf("\n");
		if (current_b != NULL)
			printf("\033[0;rank: \033[0;35m%d\033[0m\n", current_b->rank);
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

int ft_int_checker(long long a)
{
	if (a > 2147483647)
		return (0);
	if (a < -2147483648)
		return (0);
	return (1);
}

int	check_n_create(t_list **start_a, char *argv)
{
	if (argv_checker(argv) == 0)
		return (0);
	if (ft_int_checker(ft_atoi(argv)) == 0)
		return (0);
	if (create_a_stack(start_a, ft_atoi(argv)) == 0)
		return (0);
	return (1);
}

int *ft_quicksort(int *tab, int i)
{
	int pos;
	int temp;
	int k;

	temp = 0;
	k = 0;
	while(k < i)
	{
		pos = 0;
		while(pos + 1 < i)
		{
			if(tab[pos] > tab[pos + 1])
			{
				temp = tab[pos];
				tab[pos] = tab[pos + 1];
				tab[pos + 1] = temp;
				pos = 0;
			}
			pos++;
		}
		k++;
	}
	return (tab);
}
void ft_assign_rank(t_list *start_a, int *tab)
{
	int i;

	i = 0;
	while(start_a)
	{
		while(tab[i] != start_a->content)
			i++;
		start_a->rank = i;
		i = 0;
		start_a = start_a->next;
	}
}

void ft_fill_tab(t_list *start_a)
{
	int i;
	int *tab;
	t_list *temp;

	i = 0;
	tab = ftm_malloc(ft_lstsize(start_a) * sizeof(int));
	temp = start_a;
	while(temp)
	{
		tab[i] = temp->content;
		i++;
		temp = temp->next;
	}
	tab = ft_quicksort(tab,i);
	ft_assign_rank(start_a, tab);
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
	ft_fill_tab(start_a);
	read_list(start_a, start_b);
	ft_printf("\n\033[0;32m////--- AFTER ---\\\\\\\\ \n\n");
	read_list(start_a, start_b);
	ftm_free_all();
	exit (1);
}
