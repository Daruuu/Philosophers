NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread -pthread

RM = rm -rf
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = includes

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/check_arguments.c \
      $(SRC_DIR)/get_time.c \
      $(SRC_DIR)/init_structs.c \
      $(SRC_DIR)/print.c \
      $(SRC_DIR)/routine_philos.c \
      $(SRC_DIR)/utils.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# Compile of files .c to .o in the directory obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
