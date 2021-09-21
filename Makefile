# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/18 22:17:55 by oozsertt          #+#    #+#              #
#    Updated: 2021/09/21 17:16:39 by oozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C =	client

NAME_S =	server

SRCS_C =	client_main.c srcs/ft_atoi_base.c srcs/ft_atoi.c srcs/ft_itoa.c \
srcs/ft_convert_base.c srcs/ft_memset.c srcs/ft_strlen.c srcs/ft_convert_fullbinary.c

SRCS_S =	server_main.c srcs/ft_atoi_base.c srcs/ft_atoi.c srcs/ft_itoa.c \
srcs/ft_convert_base.c srcs/ft_memset.c srcs/ft_strlen.c srcs/ft_convert_fullbinary.c

OBJS_S =		$(SRCS_S:.c=.o)

OBJS_C =		$(SRCS_C:.c=.o)

FLAGS =		-Wall -Werror -Wextra

all : $(NAME_S) $(NAME_C)

$(NAME_S) : $(OBJS_S)
	gcc $(FLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME_C) : $(OBJS_C)
	gcc $(FLAGS) $(OBJS_C) -o $(NAME_C)

clean :
	rm -rf $(OBJS_S)
	rm -rf $(OBJS_C)

fclean : clean
	rm -rf $(NAME_S)
	rm -rf $(NAME_C)

re : fclean all