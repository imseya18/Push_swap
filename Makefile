NAME		:= push_swap
CFLAGS		:= -Wextra -Wall -Werror -fsanitize=address -g
FTPRINTF	:= ./printf
MM			:= ./memory_manager_2

LIBS	:= $(FTPRINTF)/libftprintf.a $(MM)/memory_mng.a
SRCS	:= push_swap.c \
			list.c \
			operation.c
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
	@$(MAKE) -C $(MM)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FTPRINTF) fclean
	@$(MAKE) -C $(MM)

re: clean all
