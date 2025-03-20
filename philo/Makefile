NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g --fsanitize=thread

RM = rm -rf
PHILO_H = includes/philosophers.h
OBJ_DIR = obj

SRC = main.c

OBJ = $(pathsubst $(SRC)/%.c, $(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -pthread -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
