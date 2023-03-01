/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:04:32 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/01 17:02:39 by mmorue           ###   ########.fr       */
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
	if(argv[0] == '-' && argv[1] == 0)
		return(0);
	while (argv[i])
	{
		if(i == 0 && argv[i] == '-')
			i++;
		if ((argv[i] < '0' || argv[i] > '9'))
			return (0);	
		i++;
	}
	return (1);
}

void	read_list(t_list *start_a)
{
	t_list *current = start_a;
    while (current != NULL)
    {
        printf("\033[0;36mMaillon address: \033[0;33m%p\033[0m\n", (void *)current);
        printf("\033[0;36mContent: \033[0;35m%d\033[0m\n", current->content);
        printf("\033[0;36mLast address: \033[0;33m%p\033[0m\n", (void *)current->last);
		printf("\033[0;36mNext address: \033[0;33m%p\033[0m\n", (void *)current->next);
        printf("\033[0;31m-------\033[0m\n");
        current = current->next;
    }
}
void	read_list_back(t_list *start_a)
{
	t_list	*temp;

	temp = ft_lstlast(start_a);
	while (temp)
	{
		ft_printf("-------%d\n", temp->content);
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
			if(check_n_create(&start_a, argv[i]) == 0)
				return (0);
	read_list(start_a);
	ft_sa(&start_a);
	ft_printf("\n\033[0;32m////--- AFTER ---\\\\\\\\ \n\n");
	read_list(start_a);
}
