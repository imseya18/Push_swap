#include "push_swap.h"

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