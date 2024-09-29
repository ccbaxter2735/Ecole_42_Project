NAME								= animal

CC									= c++

FLAGS								= -Wall -Wextra -Werror -std=c++98

FILE								= Animal.cpp \
											WrongAnimal.cpp \
											WrongCat.cpp \
											Dog.cpp \
											Cat.cpp \
											main.cpp

OBJ									= $(FILE:.cpp=.o)

$(NAME): $(OBJ)
		@echo "\nCOMPILING ANIMAL ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "ANIMAL CREATED\n"

all: $(NAME)

#$< is an automatic variable referencing the source file, file.cpp in the case of the suffix rule.
#$@ is an automatic variable referencing the target file, file.o.
# .cpp.o:
%.o : %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Deleting Animal object..."
	@rm -rf $(OBJ)
	@echo "DONE\n"

fclean: clean
	@echo "Deleting animal executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all