# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 11:17:55 by jibanez-          #+#    #+#              #
#    Updated: 2021/05/06 13:49:18 by jibanez-         ###   ########.fr        #
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
	rm -rf ./src/*.o

fclean: clean
	make fclean -C ./libft
	rm -f $(OBJS)
	rm -f libft.a
	rm -f $(NAME)
	rm -rf ./__.SYMDEF\ SORTED

re: fclean all

.PHONY:		all clean fclean re
