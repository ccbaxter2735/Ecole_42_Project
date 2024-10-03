NAME								= PmergeMe

CC									= c++

FLAGS								= -Wall -Wextra -Werror -g3 -std=c++98 

FILE								= main.cpp \
											PmergeMe.cpp \
											

OBJ									= $(FILE:.cpp=.o)

$(NAME): $(OBJ)
		@echo "\nCOMPILING PmergeMe ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "PmergeMe CREATED\n"

all: $(NAME)

#$< is an automatic variable referencing the source file, file.cpp in the case of the suffix rule.
#$@ is an automatic variable referencing the target file, file.o.
# .cpp.o:
%.o : %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Deleting PmergeMe object..."
	@rm -rf $(OBJ)
	@echo "DONE\n"

fclean: clean
	@echo "Deleting PmergeMe executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all