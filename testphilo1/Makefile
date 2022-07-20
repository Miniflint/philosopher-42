MSRC	= main.c  set_ms_correct.c
USRC	= ft_strlen.c handle_error.c ft_strdup.c __init__.c ft_atoi.c

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
	@echo "nCompiling philo.."
	@$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	@echo "\nCompiling philo objects.."
	@$(CC) -c $< -o $@

clean:
	@echo "Deleting objects.."
	@rm -f $(OBJS)

fclean: clean
	@echo "Deleting executable.."
	@rm -f $(NAME)

build:
	docker build -t arch .
	docker run -ti arch

prune:
	@echo "Deleting docker"
	@docker system prune -a --volumes

re: fclean all

.PHONY:	clean fclean all re build prune