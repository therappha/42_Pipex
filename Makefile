
NAME= pipex
CC= cc
CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)
LDFLAGS =  -L $(LIBFT_DIR) -lft
INCLUDES= ./includes
LIBFT_DIR= ./libs/libft

LIBFT= $(LIBFT_DIR)/libft.a
SRCS_DIR= ./srcs

SRCS= $(SRCS_DIR)/main.c $(SRCS_DIR)/check_envp.c $(SRCS_DIR)/handle_child.c $(SRCS_DIR)/execute.c \
$(SRCS_DIR)/handle_parent.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@echo "Cleaning Objects!"
fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "Cleaning Objects and executable"

re: fclean all

.PHONY: all clean fclean re


