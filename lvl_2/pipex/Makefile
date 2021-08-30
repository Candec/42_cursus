NAME = pipex
NAME_CHECKER = checker

LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcsv
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
# OBJ_COMMON = $(SRC_COMMON:%.c=$(OBJ_DIR)/%.o)
# OBJ_CHECKER = $(SRC_CHECKER:%.c=$(OBJ_DIR)/%.o)

HEADER = pipex.h

SRC = pipex.c \
	check_cmds.c \
	check_mode.c \
	pipe_mode.c \
	here_doc_bonus.c

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_COMMON)
	@echo $(ANSI_B_BGREEN) "compile libft" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(MAKE) all -C libft
	@echo $(ANSI_RESET) ""
	@echo $(ANSI_B_BGREEN) "compile executable" $(ANSI_RESET)$(ANSI_F_BBLACK)
	gcc $(CFLAGS) $(OBJ) $(OBJ_COMMON) $(LIBFT) -o $(NAME)
	@echo $(ANSI_RESET) ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(addprefix includes/,$(HEADER))
	@echo $(ANSI_B_BGREEN) "compile $(NAME) objects" $(ANSI_RESET)$(ANSI_F_BBLACK)
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -Iincludes -c $< -o $@
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
	@echo $(ANSI_B_RED) "Running for debbuger without sanitize" $(ANSI_RESET)
	./$(NAME) $(LIST_INTEGER)
	@./$(NAME) $(LIST_INTEGER) | wc -l
	@./$(NAME) $(LIST_INTEGER) | ./checker $(LIST_INTEGER)

runv: all
	@echo $(ANSI_B_RED) "Valgrind RESULT" $(ANSI_RESET)
	#valgrind -q --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME)

runs: all
	@echo $(ANSI_B_RED) "Running with sanitize" $(ANSI_RESET)
	gcc $(CFLAGS) -fsanitize=address $(OBJ) $(OBJ_COMMON) $(LIBFT) -o pipex
	./push_swaps $(LIST_INTEGER)
