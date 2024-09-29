NAME								= Account

CC									= c++

FLAGS								= -Wall -Wextra -Werror -std=c++98

FILE								= Account.cpp \
											tests.cpp

OBJ									= $(FILE:.cpp=.o)

$(NAME): $(OBJ)
		@echo "\nCOMPILING ACCOUNT ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "ACCOUNT CREATED\n"

all: $(NAME)

#$< is an automatic variable referencing the source file, file.cpp in the case of the suffix rule.
#$@ is an automatic variable referencing the target file, file.o.
# .cpp.o:
%.o : %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Deleting account object..."
	@rm -rf $(OBJ)
	@echo "DONE\n"

fclean: clean
	@echo "Deleting account executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all