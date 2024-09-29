#VARIABLES
NAME						= minishell

CC							= cc

DIR_DUP     				= mkdir -p $(@D)

OBJS_DIR 					= .objects/

LIBFT_PATH					= ./libft/

LIBFT_FILE					= libft.a

LIBFT_LIB					= $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

#COMPILATION FLAGS
FLAGS						= -Wall -Wextra -Werror -g3
#SOURCES
C_FILE					= 	core/main.c \
							core/prompt.c \
							core/append.c \
							core/cmd_exec_utils.c \
							core/cmd_exec.c \
							core/heredoc_utils.c \
							core/heredoc.c \
							core/pip.c \
							core/pip_utils.c \
							core/redir_utils.c \
							core/redir.c \
							core/minishell_annexe.c \
							get_next_line/get_next_line.c \
							parsing/minishell_parsing.c \
							parsing/parsing_utils.c \
							parsing/parsing_utils_1.c \
							parsing/parsing_utils_2.c \
							parsing/parsing_utils_3.c \
							parsing/parsing_tokenizer.c \
							parsing/parsing_fill_str.c \
							parsing/parsing_env.c \
							parsing/parsing_env_utils.c \
							parsing/parsing_build_list.c \
							parsing/parsing_utils_list.c \
							parsing/parsing_split.c \
							parsing/split_wsp.c \
							garbage_c/minishell_gc.c \
							garbage_c/gc_functions.c \
							garbage_c/gc_split.c \
							signal/signal.c \
							signal/sig_heredoc.c \
							built-in/echo.c \
							built-in/echo_utils.c \
							built-in/pwd.c \
							built-in/cd.c \
							built-in/cd_utils.c \
							built-in/env.c \
							built-in/unset.c \
							built-in/export.c \
							built-in/export_utils.c \
							built-in/exit.c \
							execution/exec_fct.c \
							execution/exec_minishell.c \
							execution/exec_utils.c \

SRC						= $(C_FILE)

#OBJECTS
OBJ 					= $(addprefix $(OBJS_DIR), $(SRC:.c=.o))

#RULES
$(NAME): $(OBJ) $(LIBFT_LIB)
	@echo "\033[0;33m\nCOMPILING MINISHELL...\n"
	$(CC) $(FLAGS) $(OBJ) -lreadline $(LIBFT_LIB) -o $(NAME)
	@echo "\033[1;32m./minishell created\n"
	@echo "\033[0m"

all: $(NAME)

.objects/%.o : %.c
	$(DIR_DUP)
	$(CC) $(FLAGS) -o $@ -c $<

$(LIBFT_LIB) :
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[0;33mLIBFT_lib created\n"
	@echo "\033[0m"

clean:
	@echo "\033[0;31mDeleting libft.a in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[0;31mDone\n"
	@echo "\033[1;32mDeleting minishell object...\n"
	@rm -rf .objects
	@echo "\033[1;32mDone\n"
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mDeleting minishell executable..."
	@echo "\033[0m"
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT_PATH)

re: fclean all

.PHONY : all clean fclean re
#valgrind --track-fds=yes --trace-children=yes --leak-check=full --suppressions=valgrind_readline_leaks_ignore.supp ./minishell
# ho$la$"$a"$$"b"