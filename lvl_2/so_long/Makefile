NAME = so_long

LIBFT 		= libft/libft.a
LIBMLX 		= minilibx_mms_20200219/libmlx.a
CFLAGS 		= -g -Wall -Wextra -Werror
# CFLAGS 		= -I/usr/include -Imlx_linux -O3 -g
IFLAGS		= -I minilibx_mms_20200219 -Ilmlx -I/includes
LFLAGS		= -L minilibx_mms_20200219 -lmlx 
# LFLAGS		= -I ./mlx_linux -L ./mlx_linux -lmlx -Ilmlx -lXext -lX11
AR = ar rcsv
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
MAP = ./map.ber

HEADER = so_long.h

SRC = main.c \
	handle_error.c \
	map_valid.c \
	window.c \
	mlx_utility.c \
	textures.c \
	move.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(ANSI_B_BGREEN) "compile libft" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(MAKE) all -C libft
	@echo $(ANSI_B_BGREEN) "compile libmlx" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(MAKE) -C minilibx_mms_20200219
	@echo $(ANSI_RESET) ""
	@echo $(ANSI_B_BGREEN) "compile executable" $(ANSI_RESET)$(ANSI_F_BBLACK)
	clang $(CFLAGS) $(IFLAGS) $(OBJ) $(LIBFT) $(LFLAGS) -o $(NAME)
	@echo $(ANSI_RESET) ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(addprefix includes/,$(HEADER))
	@echo $(ANSI_B_BGREEN) "compile $(NAME) objects" $(ANSI_RESET)$(ANSI_F_BBLACK)
	mkdir -p $(dir $@)
	clang $(CFLAGS) -Iincludes -c $< -o $@
	@echo $(ANSI_RESET)

clean:
	@echo $(ANSI_B_RED) "clean" $(ANSI_RESET)$(ANSI_F_BRED)
	$(MAKE) clean -C libft
	rm -rf $(OBJ_DIR)
	@echo $(ANSI_RESET) ""

fclean: clean
	@echo $(ANSI_B_RED) "fclean" $(ANSI_RESET)$(ANSI_F_BRED)
	$(MAKE) fclean -C libft
	rm -f $(NAME)
	@echo $(ANSI_RESET) ""

re: fclean all

.PHONY: all clean fclean

# colors
ANSI_RESET = "\033[0m"
ANSI_B_RED = "\033[41m"
ANSI_B_BGREEN = "\033[42;1m"
ANSI_F_BRED = "\033[31;1m"
ANSI_F_BBLACK = "\033[30;1m"


lib:
	$(MAKE) -C libft

norm:
	@echo $(ANSI_B_RED) "norminette v3" $(ANSI_RESET)
	$(MAKE) norm -C libft
	@norminette $(addprefix inc/,$(HEADER)) \
		$(addprefix src/,$(SRC))

libnorm:
	@echo $(ANSI_B_RED) "libft norminette" $(ANSI_RESET)
	$(MAKE) norm -C libft

run: all
	@echo $(ANSI_B_RED) "Running Game" $(ANSI_RESET)
	./$(NAME) $(MAP)
	# @./$(NAME)

runv: all
	@echo $(ANSI_B_RED) "Valgrind RESULT" $(ANSI_RESET)
	#valgrind -q --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME)

test: all
	@echo $(ANSI_B_RED) "Running test" $(ANSI_RESET)
	clang -I ./mlx_linux -L ./mlx_linux -lmlx -Ilmlx -lXext -lX11 mlx_linux/libmlx.a test.c  libft/libft.a mlx_linux/libmlx.a -o windows_test
	./windows_test