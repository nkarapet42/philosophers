NAME = philo

SRCS =  philo.c \
		ft_atoi.c \
		ft_init.c \
		ft_start_emul.c \
		ft_time.c \
		ft_check_functions.c \
 
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c philosophers.h Makefile
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re