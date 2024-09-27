NAME = libftprintf.a
SRCS = 	ft_len.c ft_print_csiu.c ft_print_xXp.c ft_printf.c ft_write_csiu.c ft_write_xXp.c
OBJS = ${SRCS:.c=.o}

CC = cc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
re: fclean all

.PHONY: all clean fclean re
