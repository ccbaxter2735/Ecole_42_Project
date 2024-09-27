NAME = ft_printf
LIBFT_FILE = libftprintf.a
SRCS = 	ft_len.c ft_print_csiu.c ft_print_xXp.c ft_printf.c ft_write_csiu.c ft_write_xXp.c main.c
OBJS = ${SRCS:.c=.o}

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(LIBFT_FILE): ${OBJS}
	ar rcs ${LIBFT_FILE} ${OBJS}

$(NAME): ${OBJS} ${LIBFT_FILE}
				@echo "\033[0;33m\nCOMPILING FT_PRINTF...\n"
				$(CC) $(OBJS) $(LIBFT_FILE) -o $(NAME)
				@echo "\033[1;32m./FT_PRINTF created\n"

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re
