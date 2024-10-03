NAME								= ircserv

O_DIR = OBJ

CC									= c++

FLAGS								= -Wall -Wextra -Werror -g3 -std=c++98

FILE								= Client.cpp \
										Server.cpp \
										ServerSetUp.cpp \
										Channel.cpp \
										main.cpp \
										CMD/Invite.cpp \
										CMD/Kick.cpp \
										CMD/Join.cpp \
										CMD/Nick.cpp \
										CMD/User.cpp \
										CMD/Pass.cpp \
										CMD/Mode.cpp \
										CMD/Topic.cpp \
										CMD/Part.cpp \
										CMD/Pong.cpp \
										CMD/Privmsg.cpp \
										CMD/Oper.cpp \
										CMD/Quit.cpp \
										CMD/Who.cpp \
										CMD/Whois.cpp \
										CMD/utils.cpp

OBJ									= $(addprefix $(O_DIR)/, $(FILE:.cpp=.o))

$(NAME): $(OBJ)
		@echo "\nCOMPILING ft_irc ..."
		$(CC) $(FLAGS) $(OBJ) -o $@
		@echo "ft_irc CREATED\n"

all: $(NAME)

#$< is an automatic variable referencing the source file, file.cpp in the case of the suffix rule.
#$@ is an automatic variable referencing the target file, file.o.
# .cpp.o:
$(O_DIR)/%.o : %.cpp
		@mkdir -p $(dir $@)
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Deleting ft_irc object..."
	@rm -rf $(O_DIR)
	@echo "DONE\n"

fclean: clean
	@echo "Deleting ft_irc executable..."
	@rm -f $(NAME)
	@echo "DONE\n"

re: fclean all