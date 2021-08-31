# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 12:45:23 by apinto            #+#    #+#              #
#    Updated: 2021/05/19 15:59:04 by jibanez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRS		= includes
CFLAGS 		= -Wall -Wextra -Werror -g
AR 			= ar -rcsv
NAME 		= libproject.a
SRCS		= $(wildcard ./src/*.c)
OBJS 		= $(SRCS:%.c=%.o)
CC			= gcc
PROG_NAME	= push_swap

all: $(NAME) $(CC)

$(NAME): libft.a $(OBJS)
	ar -x libft.a
	$(AR) $(NAME) *.o $(OBJS)

$(CC):
	gcc $(NAME) -I $(HDRS) $(CFLAGS) -o $(PROG_NAME)

libft.a:
	$(MAKE) libft.a -C ./libft
	mv ./libft/libft.a ./libft.a

%.o: %.c
	gcc $(CFLAGS) -I $(HDRS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -rf ft_*.o
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(OBJS)
	rm -f libft.a
	rm -f $(NAME)
	rm -f $(PROG_NAME)
	rm -rf ./__.SYMDEF\ SORTED

re: fclean all

.PHONY:		all clean fclean re
