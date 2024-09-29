NAME								= horde

CC									= c++

FLAGS								= -Wall -Wextra -Werror -std=c++98

FILE								= Zombie.cpp \
											zombieHorde.cpp \
											main.cpp

OBJ									= $(FILE:.cpp=.o)

$(NAME): $(OBJ)
		@echo "\nCOMPILING HORDE ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "HORDE CREATED\n"

all: $(NAME)

#$< is an automatic variable referencing the source file, file.cpp in the case of the suffix rule.
#$@ is an automatic variable referencing the target file, file.o.
# .cpp.o:
%.o : %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Deleting horde object..."
	@rm -rf $(OBJ)
	@echo "DONE\n"

fclean: clean
	@echo "Deleting horde executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all