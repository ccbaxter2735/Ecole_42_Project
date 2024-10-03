NAME								= convert

CC									= c++

FLAGS								= -Wall -Wextra -Werror -std=c++98

FILE								= main.cpp \
											ScalarConverter.cpp \

OBJ									= $(FILE:.cpp=.o)

$(NAME): $(OBJ)
		@echo "\nCOMPILING CONVERT ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "CONVERT CREATED\n"

all: $(NAME)

#$< is an automatic variable referencing the source file, file.cpp in the case of the suffix rule.
#$@ is an automatic variable referencing the target file, file.o.
# .cpp.o:
%.o : %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Deleting convert object..."
	@rm -rf $(OBJ)
	@echo "DONE\n"

fclean: clean
	@echo "Deleting convert executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all