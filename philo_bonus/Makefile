SRCD	= ./src


SRCF	= main.c


SRCO	= $(addprefix $(SRDC)/,$(SRCF))

FILES	= $(SRCO)
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
	@prinf "\nDone\n"

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
