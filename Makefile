NAME		:= push_swap
CFLAGS		:= -Wextra -Wall -Werror
FTPRINTF	:= ./printf

LIBS	:= $(FTPRINTF)/libftprintf.a
SRCS	:= 	push_swap.c \
			list.c \
			operation.c \
			operation_2.c \
			to_delete.c \
			pre_sort_rank.c \
			radix_sort.c \
			memory_manager_2.c \
			memory_manager_utils.c \
			memory_manager.c \
			radix_sort_utils.c
OBJS	:= $(SRCS:.c=.o)
CC 		= gcc $(CFLAGS)

all: ftprintf $(NAME)

ftprintf:
	@$(MAKE) -C $(FTPRINTF)

$(NAME): $(SRCS) $(OBJS) 
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(FTPRINTF) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FTPRINTF) fclean

re: clean all
