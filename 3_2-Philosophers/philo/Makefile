NAME			= philo

CC				= cc 

FLAG			= -Wall -Wextra -Werror -g

C_FILE		= main.c \
						philo_utils.c \
						philo_utils2.c \
						philo_fct.c \
						philo_fct2.c \
						routine.c \
						dead.c \
						parsing.c \
						init_forks.c \
						init_philo.c \
						init_thread.c \

SRC_DIR		=	./core/

INC_DIR		=	./includes/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

$(NAME): $(OBJ)
	@echo "\033[0;33m\nCOMPILING PHILOSOPHER...\n"
	$(CC) $(FLAG) $(OBJ) -o $(NAME)
	@echo "\033[0;33m./philo created\n"

all : $(NAME)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

clean:
	@echo "\033[1;32mDeleting philo object..."
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[1;32mDeleting philo executable..."
	@rm -f $(NAME)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re