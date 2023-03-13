NAME = libft.a

SOURCES =   ft_atoi.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_itoa.c \
			ft_split.c

OBJECTS = $(SOURCES:.c=.o)


FLAGS = -Wall -Wextra -Werror

CC = gcc $(FLAGS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)

$(NAME): $(SOURCES) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
