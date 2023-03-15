/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:41:28 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/15 18:01:33 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"./printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	int				rank;
	int				*binary;
	struct s_list	*next;
	struct s_list	*last;
}	t_list;

typedef struct s_memng
{
	void			*mem;
	int				type;
	int				fd;
	struct s_memng	*next;
}	t_memng;

// FONCTION LISTE 
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

// FONCTION OPERATION
int		ft_sa_sb(t_list **stack, int flag);
int		ft_ra_rb(t_list **stack, int flag);
int		ft_rra_rrb(t_list **stack, int flag);
void	ss(t_list **stack_a, t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rrr(t_list**stack_a, t_list **stack_b);
int		ft_pa_pb(t_list **main, t_list **target, int flag);

// FONCTION CREATION & CHECK LISTE
int		ft_int_checker(long long a);
int		check_n_create(t_list **start_a, char **argv);
int		argv_checker(char *argv);
int		create_a_stack(t_list **start, int a);

//	FONCTION ERROR
void	ft_error(void);

// PRE SORT & RANK
void	ft_swap(int *a, int *b);
int		*ft_quicksort(int *tab, int end, int start, int size);
void	ft_assign_rank(t_list *start_a, int *tab);
void	ft_fill_tab(t_list *start_a);

// RADIX SORT
void	ft_radix_sort(t_list **start_a, t_list **start_b);
void	sort_big_stack(t_list **start_a, t_list **start_b, int rank_size);
void	sort_small_stack(t_list **a);
int		ft_check_nbr(int nbr, int n);
int		ft_check_if_sort(t_list *start_a);

// SORT FOR 5 
void	sort_medium_stack(t_list **start_a, t_list **start_b);
void	ft_medium_r_rotate(t_list **start_a, int size);
void	ft_medium_rotate(t_list **start_a, int size);
int		check_pos(t_list *start_a, int rank);

// TEST BINARY
void	sort_big_stack_binary(t_list **start_a, t_list **start_b);
int		*int_to_binary(unsigned int n);

// DELETE !!!!!
void	read_list(t_list *start_a, t_list *start_b);

// MEMORY MANAGER
t_memng	**ft_head_lst(void);
t_memng	*ft_memnew_manager(void *mem, int type, int fd);
void	ft_memadd_back_manager(t_memng **lst, t_memng *new);
int		ft_is_in_lst(void *mem);
void	*ftm_malloc(size_t sz);
void	ftm_free(void *mem);
void	ftm_free_all(void);
void	ftm_add_track(void *mem);
void	ftm_rm_track(void *mem);
#endif