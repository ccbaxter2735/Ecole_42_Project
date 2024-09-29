NAME								= battle

CC									= c++

FLAGS								= -Wall -Wextra -Werror -std=c++98

FILE								= ClapTrap.cpp \
											main.cpp

OBJ									= $(FILE:.cpp=.o)

$(NAME): $(OBJ)
		@echo "\nCOMPILING BATTLE ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "BATTLE CREATED\n"

all: $(NAME)

#$< is an automatic variable referencing the source file, file.cpp in the case of the suffix rule.
#$@ is an automatic variable referencing the target file, file.o.
# .cpp.o:
%.o : %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Deleting battle object..."
	@rm -rf $(OBJ)
	@echo "DONE\n"

fclean: clean
	@echo "Deleting battle executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all