R=\e[0;31m
G=\e[0;32m
B=\e[0;34m
C=\e[0;36m
W=\e[0;37m

MSRC	= main.c routine.c
USRC	= ft_strlen.c handle_error.c ft_strdup.c __init__.c ft_atoi.c free_mem.c

ODIR	= ./obj
MDIR	= ./src/main
UDIR	= ./src/utils

MSRCS	= $(addprefix $(MDIR)/,$(MSRC))
USRCS	= $(addprefix $(UDIR)/,$(USRC))

FILES	= $(MSRCS) $(USRCS)
OBJS	= $(FILES:.c=.o)
CFLAGS	= -Werror -Wextra -Wall -pthread
ifeq ($(DEBUG), debug)
	CFLAGS += -fsanitize=address -g3
endif
NAME	= philo
CC		= gcc $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@printf "\n$(G)Done$(W)%50s\n" " "

%.o: %.c
	@printf "$(G)Generating minishell objects... $(C)%-33.33s$(W)\r" $@
	@$(CC) -c $< -o $@

clean:
	@printf "$(R)Deleting objects..$(W)\n"
	@rm -f $(OBJS)

fclean: clean
	@printf "$(R)Deleting executable..$(W)\n"
	@rm -f $(NAME)
	@printf "$(R)Done$(W)\n"

build:
	docker build -t arch .
	docker run -ti arch

prune:
	@printf "Deleting docker"
	@docker system prune -a --volumes

re: fclean all

test: re
	@echo "Launching philo with '3 4 5 6'\n"
	@sleep 1
	./philo 3 4 5 6

.PHONY:	clean fclean all re build prune
