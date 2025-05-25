# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 12:22:16 by samatsum          #+#    #+#              #
#    Updated: 2025/05/25 16:05:11 by samatsum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unit_test
FRAMEWORK_DIR = framework
FRAMEWORK_LIB = libunit.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

# フレームワーク関連
FRAMEWORK_SRCS_DIR = $(FRAMEWORK_DIR)/srcs
FRAMEWORK_OBJS_DIR = $(FRAMEWORK_DIR)/objs
FRAMEWORK_INCLUDES = -I$(FRAMEWORK_DIR)/includes

FRAMEWORK_SRCS = 	$(FRAMEWORK_SRCS_DIR)/load_test.c \
					$(FRAMEWORK_SRCS_DIR)/launch_tests.c \
					$(FRAMEWORK_SRCS_DIR)/execute_test.c \
					$(FRAMEWORK_SRCS_DIR)/utils.c

FRAMEWORK_OBJS = $(patsubst $(FRAMEWORK_SRCS_DIR)/%.c,$(FRAMEWORK_OBJS_DIR)/%.o,$(FRAMEWORK_SRCS))

# テスト関連
TEST_SRCS_DIR = tests/test_srcs
TEST_OBJS_DIR = tests/test_objs
TEST_INCLUDES = -Itests/test_includes

# main.cは別途処理
MAIN_SRC = tests/main.c
MAIN_OBJ = tests/test_objs/main.o

# test_srcs内のファイル
TEST_SRCS = $(TEST_SRCS_DIR)/00_launcher.c \
			$(TEST_SRCS_DIR)/01_ok_test.c \
			$(TEST_SRCS_DIR)/02_ko_test.c \
			$(TEST_SRCS_DIR)/03_sigsegv_test.c \
			$(TEST_SRCS_DIR)/04_sigbus_test.c

TEST_OBJS = $(patsubst $(TEST_SRCS_DIR)/%.c,$(TEST_OBJS_DIR)/%.o,$(TEST_SRCS))

# 全てのテストオブジェクトファイル
ALL_TEST_OBJS = $(TEST_OBJS) $(MAIN_OBJ)

all: $(NAME)

# 静的ライブラリの作成
$(FRAMEWORK_LIB): $(FRAMEWORK_OBJS)
	ar rc $@ $^
	ranlib $@

# フレームワークのオブジェクトファイル作成ルール
$(FRAMEWORK_OBJS_DIR)/%.o: $(FRAMEWORK_SRCS_DIR)/%.c
	@mkdir -p $(FRAMEWORK_OBJS_DIR)
	$(CC) $(CFLAGS) $(FRAMEWORK_INCLUDES) -c $< -o $@

# テストのオブジェクトファイル作成ルール
$(TEST_OBJS_DIR)/%.o: $(TEST_SRCS_DIR)/%.c
	@mkdir -p $(TEST_OBJS_DIR)
	$(CC) $(CFLAGS) $(FRAMEWORK_INCLUDES) $(TEST_INCLUDES) -c $< -o $@

# main.c用のコンパイルルール
$(MAIN_OBJ): $(MAIN_SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(FRAMEWORK_INCLUDES) $(TEST_INCLUDES) -c $< -o $@

# 実行ファイルの作成
$(NAME): $(ALL_TEST_OBJS) $(FRAMEWORK_LIB)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) -r $(FRAMEWORK_OBJS_DIR) $(TEST_OBJS_DIR)

fclean: clean
	$(RM) $(FRAMEWORK_LIB) $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test