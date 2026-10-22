NAME    = practiceshell

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

SRC     = practiceshell.c exercises.c session.c grader.c \
          exam.c practice.c utils.c
OBJ     = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/practiceshell.h $(SRC_DIR)/exercises.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) .tmp

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
