# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terussar <terussar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 21:14:56 by khle              #+#    #+#              #
#    Updated: 2024/01/19 18:41:21 by terussar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -MMD -g3
LIBFT_PATH	=	./libft/
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FILE	=	libmlx.a
MLX_FLAG	=	-lX11 -lXext -lm
MLX_PATH	=	./minilibx-linux/
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

INCLUDES	=	-I $(HEADER)

SRC_PATH	=	sources/
HEADER		=	includes/
OBJ_PATH	=	objs/
SUB_OBJ		=	objs/parsing \
						objs/utils \
						objs/init_mlx \
						objs/raycast \
						objs/minimap \

SOURCES		=	cub3D.c \
				parsing/check_map.c \
				parsing/parsing.c \
				parsing/utils_parsing.c\
				utils/ft_itoa2.c \
				utils/ft_split2.c \
				utils/libft.c \
				init_mlx/init_image.c \
				init_mlx/utils_init.c \
				raycast/raycast.c \
				raycast/fond_color.c \
				raycast/utils_cast.c \
				raycast/clear.c \
				raycast/press_key.c \
				minimap/mini.c \
				minimap/mini_utils.c \

SRCS		=	$(addprefix $(SRC_PATH),$(SOURCES))
OBJS		=	$(addprefix $(OBJ_PATH),$(SOURCES:.c=.o))
DEPS		=	$(addprefix $(OBJ_PATH),$(SOURCES:.c=.d))	

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@$(CC) $(FLAGS) -c $< -o $@

all: tmp $(NAME)

$(LIBFT_LIB) :
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

$(MLX_EX) :
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"

tmp:
		@mkdir -p $(OBJ_PATH) $(SUB_OBJ)

$(NAME):  $(LIBFT_LIB) $(MLX_EX) $(OBJS)
	@echo "\033[0;33m\nCOMPILING CUB3D...\n"
	$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m./cub3D created\n"


clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting cub3D object...\n"
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;32mDone\n"
			
fclean: clean
	@echo "\033[0;31mDeleting cub3D executable..."
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re 
