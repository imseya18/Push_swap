/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:04:32 by mmorue            #+#    #+#             */
/*   Updated: 2023/02/27 18:00:11 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
void	create_a_stack(t_list **start, int a)
{
	t_list	*new;

	new = ft_lstnew(a);
	if (new == 0)
	{
											//gerer cas erreurs 
	}
	ft_lstadd_back(start, new);
}
int argv_checker(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if(argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
void read_list(t_list *start)
{
	while(start)
	{
		printf("%d\n", start->content);
		start = start->next;
	}
}
int	main(int argc, char **argv)
{
	int i;
	t_list	*start;
	int temp;
	
	start = 0;
	i = 0;
	temp = 0;
	if (argc < 2)
		return (0);
	else
	{
		while(++i < argc)
		{
			if (argv_checker(argv[i]) == 0)
				return (0);
		}		
		i = 0;
		while (++i < argc)
			create_a_stack(&start, ft_atoi(argv[i]));
	}
	read_list(start);
}
