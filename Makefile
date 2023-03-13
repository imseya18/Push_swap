NAME		:= push_swap
CFLAGS		:= -Wextra -Wall -Werror -g -fsanitize=address
FTPRINTF	:= ./printf
MM			:= ./memory_manager_2

LIBS	:= $(FTPRINTF)/libftprintf.a $(MM)/memory_mng.a
SRCS	:= push_swap.c \
			list.c \
			operation.c \
			operation_2.c \
			to_delete.c \
			pre_sort_rank.c \
			radix_sort.c
OBJS	:= $(SRCS:.c=.o)
CC 		= gcc $(CFLAGS)

all: mm ftprintf $(NAME)

ftprintf:
	@$(MAKE) -C $(FTPRINTF)

mm:
	@$(MAKE) -C $(MM)

$(NAME): $(SRCS) $(OBJS) 
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(FTPRINTF) clean
	@$(MAKE) -C $(MM) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FTPRINTF) fclean
	@$(MAKE) -C $(MM) fclean

re: clean all
