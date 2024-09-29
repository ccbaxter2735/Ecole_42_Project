NAME								= phoneBook

CC									= c++

FLAGS								= -Wall -Wextra -Werror -std=c++98

FILE								= Contact.cpp \
											PhoneBook.cpp \
											main.cpp

OBJ									= $(FILE:.cpp=.o)

$(NAME): $(OBJ)
		@echo "\nCOMPILING PHONEBOOK ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "PHONEBOOK CREATED\n"

all: $(NAME)

#$< is an automatic variable referencing the source file, file.cpp in the case of the suffix rule.
#$@ is an automatic variable referencing the target file, file.o.
# .cpp.o:
%.o : %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Deleting phoneBook object..."
	@rm -rf $(OBJ)
	@echo "DONE\n"

fclean: clean
	@echo "Deleting phoneBook executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all