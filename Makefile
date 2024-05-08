# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 11:03:31 by mhummel           #+#    #+#              #
#    Updated: 2024/05/07 12:16:23 by mhummel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client.c
SERVER = server.c

CLIENT_EXE = client
SERVER_EXE = server

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): libft printf $(CLIENT_EXE) $(SERVER_EXE)
	@echo "\033[32m" Compiled"\033[0m"

$(CLIENT_EXE): $(CLIENT) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(CLIENT) $(LIBFT) $(PRINTF) -o $(CLIENT_EXE)

$(SERVER_EXE): $(SERVER) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(SERVER) $(LIBFT) $(PRINTF) -o $(SERVER_EXE)

libft:
	@make -C libft

printf:
	@make -C ft_printf

clean:
	rm -f $(CLIENT_EXE) $(SERVER_EXE)
	@make -C libft clean
	@make -C ft_printf clean
	@echo "Cleaned"

fclean: clean
	rm -f $(LIBFT) $(PRINTF)
	@echo "Fcleaned"

re: fclean all

.PHONY: all clean fclean re libft printf