R=\e[0;31m
G=\e[0;32m
B=\e[0;34m
C=\e[0;36m
W=\e[0;37m

MSRC	= main.c
USRC	= ft_strlen.c handle_error.c ft_strdup.c __init__.c ft_atoi.c free_mem.c

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
	@echo "\n$(G)Done$(W)"
	@$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	@printf "$(G)Compiling philo objects.. $(C)$<$(W)                                \r"
	@$(CC) -c $< -o $@

clean:
	@echo "$(R)Deleting objects..$(W)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(R)Deleting executable..$(W)"
	@rm -f $(NAME)
	@echo "$(R)Done$(W)"

build:
	docker build -t arch .
	docker run -ti arch

prune:
	@echo "Deleting docker"
	@docker system prune -a --volumes

re: fclean all

.PHONY:	clean fclean all re build prune
