NAME								= attack

CC									= c++

FLAGS								= -Wall -Wextra -Werror -std=c++98

FILE								= main.cpp \
											Weapon.cpp \
											HumanA.cpp \
											HumanB.cpp \

OBJ									= $(FILE:.cpp=.o)

$(NAME): $(OBJ)
		@echo "\nCOMPILING ATTACK ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "ATTACK CREATED\n"

all: $(NAME)

#$< is an automatic variable referencing the source file, file.cpp in the case of the suffix rule.
#$@ is an automatic variable referencing the target file, file.o.
# .cpp.o:
%.o : %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Deleting  object..."
	@rm -rf $(OBJ)
	@echo "DONE\n"

fclean: clean
	@echo "Deleting attack executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all