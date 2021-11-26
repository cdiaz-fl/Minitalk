SERVER = server
CLIENT = client

SRC 	=	server.c\
				client.c\
CC 		= gcc
FLAGS = -Wall -Werror -Wextra -g
LIBS	= -L./libft -lft
LIBFT	= libft.a

all : $(LIBFT) $(SERVER) $(CLIENT) 

$(LIBFT) : 
	@make -C libft

$(SERVER) : server.o includes/minitalk.h
	@$(CC) server.o $(LIBS) -o $@
	@printf "\e[38;5;226mOnce more unto the breach, dear friends, once more 😑\e[0m\n"
$(CLIENT) : client.o includes/minitalk.h
	@$(CC) client.o $(LIBS) -o $@

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@make clean -C libft
	@rm -f *.o
	@printf "\e[38;5;206m.o files deleted🚽\e[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -rf $(CLIENT).dSYM
	@rm -rf $(SERVER).dSYM
	@rm -rf $(CLIENT)
	@rm -rf $(SERVER)
	@printf "\e[38;5;200mBinaries deleted🗑\e[0m\n"

re: fclean all

.PHONY: all clean fclean re
