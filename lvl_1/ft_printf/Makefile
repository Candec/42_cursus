# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 12:45:23 by apinto            #+#    #+#              #
#    Updated: 2021/05/10 19:52:21 by jibanez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRS		= includes
CFLAGS 		= -Wall -Wextra -Werror
AR 			= ar -rcsv
NAME 		= libftprintf.a
SRCS		= $(wildcard ./src/*.c)
OBJS 		= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): libft.a $(OBJS)
	ar -x libft.a
	$(AR) $(NAME) *.o $(OBJS)

libft.a:
	$(MAKE) libft.a -C ./libft
	mv ./libft/libft.a ./libft.a

%.o: %.c
	gcc $(CFLAGS) -I $(HDRS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -rf ft_*.o

fclean: clean
	make fclean -C ./libft
	rm -f $(OBJS)
	rm -f libft.a
	rm -f $(NAME)
	rm -rf ./__.SYMDEF\ SORTED

re: fclean all

.PHONY:		all clean fclean re
