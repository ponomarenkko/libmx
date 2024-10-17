NAME = libmx.a
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: install

install: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)

uninstall: clean
	@rm -f $(NAME)

reinstall: uninstall install

