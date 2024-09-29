NAME								= brain

CC									= c++

FLAGS								= -Wall -Wextra -Werror -std=c++98

FILE								= Zombie.cpp \
											NewZombie.cpp \
											RandomChump.cpp \
											main.cpp

OBJ									= $(FILE:.cpp=.o)

$(NAME): $(OBJ)
		@echo "\nCOMPILING BRAIN ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "BRAIN CREATED\n"

all: $(NAME)

#$< is an automatic variable referencing the source file, file.cpp in the case of the suffix rule.
#$@ is an automatic variable referencing the target file, file.o.
# .cpp.o:
%.o : %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Deleting brain object..."
	@rm -rf $(OBJ)
	@echo "DONE\n"

fclean: clean
	@echo "Deleting brain executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all