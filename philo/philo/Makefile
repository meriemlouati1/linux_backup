CC = cc 
CFLAGS = -Wall -Werror -Wextra

NAME = philo

SRCS = parsing.c utils.c

OBJCS =$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJCS)
	$(CC) $(CFLAGS) -o $@ $^ 

clean: 
	rm -rf $(OBJCS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all
