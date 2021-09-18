# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/18 22:17:55 by oozsertt          #+#    #+#              #
#    Updated: 2021/09/18 23:32:18 by oozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

CLIENTFILES.C = client_main.c srcs/ft_itoa.c srcs/ft_convert_base.c \
srcs/ft_atoi_base.c srcs/ft_strlen.c

CLIENTFILES.O = client_main.o ft_itoa.o ft_convert_base.o \
ft_atoi_base.o ft_strlen.o

SERVERFILES.C = server_main.c srcs/ft_convert_base.c srcs/ft_atoi.c \
srcs/ft_memset.c

SERVERFILES.O = server_main.o ft_convert_base.o ft_atoi.o \
ft_memset.o

all :
	@gcc -c $(FLAGS) $(CLIENTFILES.C)
	@gcc -o client $(CLIENTFILES.O)
	@gcc -c $(FLAGS) $(SERVERFILES.C)
	@gcc -o server $(SERVERFILES.O)

clean :
	@rm -rf $(CLIENTFILES.O) $(SERVERFILES.O)

fclean : clean
	@rm -rf $(NAME) ./server
	@rm -rf $(NAME) ./client

re : fclean all