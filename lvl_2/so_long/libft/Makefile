NAME = libft.a
HEADER	= libft.h
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)
AR = ar -rcs
DIR_OBJS = obj/
SRCS = $(wildcard *.c)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $?

$(DIR_OBJS)%.o: %.c $(HEADER)
	gcc $(CFLAGS) -include $(HEADER) -c $< -o $@

$(OBJS):	| $(DIR_OBJS)
$(DIR_OBJS):
	mkdir $(DIR_OBJS)

clean:
	rm -rf $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	@norminette $(HEADER) $(SRCS)

norm2:
	@norminette2 $(HEADER) $(SRCS)

.PHONY:		all clean fclean re
