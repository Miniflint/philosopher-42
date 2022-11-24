R=\e[0;31m
G=\e[0;32m
B=\e[0;34m
C=\e[0;36m
W=\e[0;37m

MSRC	= main.c routine.c eating.c thinking.c sleeping.c timing.c writing.c
USRC	= ft_isdigit.c handle_error.c __init__.c ft_atoi.c free_mem.c check_is_dead.c

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
CC	= gcc $(CFLAGS)
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@printf "\n$(G)Done$(W)%50s\n" " "

%.o: %.c
	@printf "$(G)Generating philo objects... $(C)%-33.33s$(W)\r" $@
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
	@printf "$(G)Launching test 1: 3 400 200 100\n$(W)"
	@./philo 3 400 200 100
	@sleep 1
	@printf "$(G)Launching test 2: 5 7 9 0\n$(W)"
	@./philo 5 7 9 0
	@sleep 1
	@printf "$(G)Launching test 3: 10 5 7 8\n$(W)"
	@./philo 10 5 7 8

.PHONY:	clean fclean all re build prune
