NAME						= pipex

CC							= cc

FLAGS						= -Wall -Wextra -Werror -g3

LIBFT_PATH			= ./libft/

LIBFT_FILE			= libft.a

LIBFT_LIB				= $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

C_FILE					= pipe/pipex_utils.c \
									pipe/main.c \
									pipe/fct_annexe.c \

SRC							= $(C_FILE)

OBJ							= $(SRC:.c=.o)


$(NAME): $(OBJ) $(LIBFT_LIB)
	@echo "\033[0;33m\nCOMPILING PIPEX...\n"
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)
	@echo "\033[1;32m./pipex created\n"

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT_LIB) :
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[0;33mLIBFT_lib created\n"

clean:
	@echo "\033[0;31mDeleting libft.a in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[0;31mDone\n"
	@echo "\033[1;32mDeleting pipex object...\n"
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting pipex executable..."
	@rm -f $(NAME)

re: fclean all