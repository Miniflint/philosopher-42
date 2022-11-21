SRCD	= ./src
UTILD	= $(SRCD)/utils

SRCF	= main.c
UTILF	= ft_atoi.c init.c ft_get_t.c

SRCO	= $(addprefix $(SRCD)/, $(SRCF))
UTILO	= $(addprefix $(UTILD)/, $(UTILF))

FILES	= $(SRCO) $(UTILO)
OBJS	= $(FILES:.c=.o)

CFLAGS	= -Werror -Wextra -Wall -pthread
ifeq ($(DEBUG),debug)
	CFLAGS += -fsanitize=address -g3
endif
NAME	= philo_bonus
CC	= gcc $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@printf "\nDone\n"

%.o: %.c
	@printf "Generating philo objects... %-33.33s\r" $@
	@$(CC) -c $< -o $@

clean:
	@printf "Deleting objects\n"
	@rm -f $(OBJS)

fclean: clean
	@printf "Deleting executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re  
