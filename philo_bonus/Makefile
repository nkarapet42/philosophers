NAME = philo_bonus

SRCS =  philo_bonus.c \
		ft_atoi_bonus.c \
		ft_bonus_init.c \
		ft_time_bonus.c \
		ft_check_functions_bonus.c \
		ft_start_emul_bonus.c \
 
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c philosophers_bonus.h Makefile
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re