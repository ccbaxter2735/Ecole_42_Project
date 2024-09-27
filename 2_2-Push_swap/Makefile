NAME					=	push_swap

NAME_BONUS		= checker

CC						=	cc

FLAG					= -Wall -Wextra -Werror -g3

LIBFT_PATH		=	./libft/

LIBFT_FILE		= libft.a

FTPRINTF_PATH	=	./ft_printf/

FTPRINTF_FILE	= libftprintf.a

LIBFT_LIB			= $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

FTPRINTF_LIB	= $(addprefix $(FTPRINTF_PATH), $(FTPRINTF_FILE))

C_FILE				=	parsing/parsing.c	\
								parsing/utils.c \
								parsing/sort.c \
								parsing/string.c \
								parsing/fct_swap_push_rot.c	\
								parsing/fct_swap_push_rot_2.c	\
								parsing/main.c \
								algo/utils_algo.c \
								algo/utils_algo_2.c \
								algo/algo_simple.c \
								algo/algo_complexe_utils.c \
								algo/algo_complexe_annexe.c \
								algo/choose_case.c \
								algo/algo_complexe.c \

C_FILE_BONUS 	= parsing/parsing.c	\
								parsing/utils.c \
								parsing/sort.c \
								parsing/string.c \
								parsing/fct_swap_push_rot.c	\
								parsing/fct_swap_push_rot_2.c	\
								bonus/checker_bonus.c \
								algo/utils_algo.c \
								algo/utils_algo_2.c \
								algo/algo_simple.c \
								algo/algo_complexe_utils.c \
								algo/algo_complexe_annexe.c \
								algo/choose_case.c \
								algo/algo_complexe.c \

INC_DIR				= ./includes/

SRC						= $(C_FILE)

SRC_BONUS			= $(C_FILE_BONUS) 

OBJ						= $(SRC:.c=.o)

OBJ_BONUS			= $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ) $(LIBFT_LIB) $(FTPRINTF_LIB)
		@echo "\033[0;33m\nCOMPILING PUSH_SWAP...\n"
		$(CC) $(OBJ) $(LIBFT_LIB) $(FTPRINTF_LIB) -o $(NAME)
		@echo "\033[1;32m./push_swap created\n"

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT_LIB) $(FTPRINTF_LIB)
		@echo "\033[0;33m\nCOMPILING CHECKER...\n"
		$(CC) $(OBJ_BONUS) $(LIBFT_LIB) $(FTPRINTF_LIB) -o $(NAME_BONUS)
		@echo "\033[1;32m./checker created\n"

all: $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS)

.c.o:
		$(CC) $(FLAG) -c $< -o $@

$(FTPRINTF_LIB) :
	@echo "\033[0;33m\nCOMPILING $(FTPRINTF_PATH)\n"
	@make -C $(FTPRINTF_PATH)
	@echo "\033[1;32mFTPRINTF_lib created\n"

$(LIBFT_LIB) :
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

clean:
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[0;31mDeleting Obj file in $(FTPRINTF_PATH)...\n"
	@make clean -sC $(FTPRINTF_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting push_swap object...\n"
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting checker object...\n"
	@rm -f $(OBJ_BONUS)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting push_swap executable..."
	@rm -f $(NAME)
	@echo "\033[0;31mDeleting checker executable..."
	@rm -f $(NAME_BONUS)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	@make fclean -C $(FTPRINTF_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: clean fclean re