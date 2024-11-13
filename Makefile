##
## EPITECH PROJECT, 2024
## my_ls
## File description:
## ./Makefile
##

MAKEFLAGS += -j

NAME := my_ls

LIB_NAME := libmy.a

SRC := $(wildcard src/*.c)
SRC += $(wildcard src/flags/*.c)
SRC += $(wildcard src/utils/*.c)

LIB_SRC := $(wildcard lib/my/*.c)
LIB_SRC += $(wildcard lib/my/printf/*.c)
LIB_SRC += $(wildcard lib/my/printf/baby/*.c)
LIB_SRC += $(wildcard lib/my/printf/handler/*.c)

BUILD_DIR := .build

TEST_SRC := tests/main.c
TEST_OBJ := $(TEST_SRC:%.c=$(BUILD_DIR)/%.o)

OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)
LIB_OBJ := $(LIB_SRC:%.c=$(BUILD_DIR)/%.o)

CC := gcc

CFLAGS += -Wall -Wextra
CFLAGS += -iquote ./include
CFLAGS += -Wno-unused-parameter

LDFLAGS += -L .
LDLIBS := -lmy

oui: $(NAME)

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIB_NAME): $(LIB_OBJ)
	ar rc $(LIB_NAME) $(LIB_OBJ)

$(NAME): $(LIB_NAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) -r $(NAME) $(BUILD_DIR)
	$(RM) $(LIB_NAME)

.NOTPARALLEL: re
re:	fclean oui

test: $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJ) $(LDFLAGS) $(LDLIBS)

tests_run: test
	./$<

.PHONY: all clean fclean re test tests_run
