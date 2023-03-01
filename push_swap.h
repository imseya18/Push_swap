/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:41:28 by mmorue            #+#    #+#             */
/*   Updated: 2023/02/28 18:28:42 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"./printf/ft_printf.h"
# include	"./memory_manager_2/memory_manager.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*last;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	read_list(t_list *start);
int		argv_checker(char *argv);
int		create_a_stack(t_list **start, int a);
int		ft_lstsize(t_list *lst);
#endif