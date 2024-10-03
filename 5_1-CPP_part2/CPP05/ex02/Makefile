NAME								= bureaucrat

CC									= c++

FLAGS								= -Wall -Wextra -Werror -g3 -std=c++98

FILE								= Bureaucrat.cpp \
											AForm.cpp \
											PresidentialPardonForm.cpp \
											main.cpp \
											RobotomyRequestForm.cpp \
											ShrubberyCreationForm.cpp \

OBJ									= $(FILE:.cpp=.o)

$(NAME): $(OBJ)
		@echo "\nCOMPILING BUREAUCRAT ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "BUREAUCRAT CREATED\n"

all: $(NAME)

#$< is an automatic variable referencing the source file, file.cpp in the case of the suffix rule.
#$@ is an automatic variable referencing the target file, file.o.
# .cpp.o:
%.o : %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Deleting bureaucrat object..."
	@rm -rf $(OBJ)
	@echo "DONE\n"

fclean: clean
	@echo "Deleting bureaucrat executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all