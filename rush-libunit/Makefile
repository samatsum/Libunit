#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 12:22:16 by samatsum          #+#    #+#              #
#    Updated: 2025/05/24 15:28:52 by samatsum         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = unit_test
FRAMEWORK_DIR = framework
FRAMEWORK_LIB = libunit.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

FRAMEWORK_SRCS_DIR = $(FRAMEWORK_DIR)/srcs
FRAMEWORK_OBJS_DIR = $(FRAMEWORK_DIR)/objs
FRAMEWORK_SRCS = 	$(FRAMEWORK_SRCS_DIR)/load_test.c \
					$(FRAMEWORK_SRCS_DIR)/launch_tests.c \
					$(FRAMEWORK_SRCS_DIR)/execute_test.c \
					$(FRAMEWORK_SRCS_DIR)/utils.c \
					$(FRAMEWORK_SRCS_DIR)/main.c

FRAMEWORK_OBJS = $(patsubst $(FRAMEWORK_SRCS_DIR)/%.c,$(FRAMEWORK_OBJS_DIR)/%.o,$(FRAMEWORK_SRCS))

TEST_SRCS_DIR = tests/test_srcs
TEST_OBJS_DIR = tests/test_objs
TEST_SRCS = $(TEST_SRCS_DIR)/strlen/00_launcher.c \
           $(TEST_SRCS_DIR)/strlen/01_basic_test.c \
           $(TEST_SRCS_DIR)/strlen/02_null_test.c \
           $(TEST_SRCS_DIR)/strlen/03_segfault_test.c \
           $(TEST_SRCS_DIR)/strlen/04_bus_error_test.c \

TEST_OBJS = $(patsubst $(TEST_SRCS_DIR)/%.c,$(TEST_OBJS_DIR)/%.o,$(TEST_SRCS))

all: $(NAME)

$(FRAMEWORK_LIB): $(FRAMEWORK_OBJS)
	ar rc $@ $^
	ranlib $@

# フレームワークのオブジェクトファイル作成ルール
$(FRAMEWORK_OBJS_DIR)/%.o: $(FRAMEWORK_SRCS_DIR)/%.c
	@mkdir -p $(FRAMEWORK_OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# テストのオブジェクトファイル作成ルール（修正後）
$(TEST_OBJS_DIR)/%.o: $(TEST_SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(TEST_OBJS) $(FRAMEWORK_LIB)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) -r $(FRAMEWORK_OBJS_DIR) $(TEST_OBJS_DIR)

fclean: clean
	$(RM) $(FRAMEWORK_LIB) $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test