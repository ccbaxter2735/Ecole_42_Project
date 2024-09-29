NAME								= reference

CC									= c++

FLAGS								= -Wall -Wextra -Werror -std=c++98

FILE								= main.cpp

OBJ									= $(FILE:.cpp=.o)

$(NAME): $(OBJ)
		@echo "\nCOMPILING REF ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "REF CREATED\n"

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
	@echo "Deleting reference executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all