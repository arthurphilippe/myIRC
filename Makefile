##
## EPITECH PROJECT, 2018
## nm
## File description:
## Makefile
##

CC		=	gcc

RM		=	rm -vf

NAME		=	server

MAIN		=	src/main.c

SRCS		=	src/manager/create.c		\
			src/manager/handle_get.c	\
			src/manager/loop.c		\
			src/manager/delete.c		\
			src/manager/channel_join.c	\
			src/manager/channel_leave.c	\
			src/manager/channel_destroy.c	\
			src/manager/client.c	\
			src/handle/port_read.c		\
			src/handle/port_create.c	\
			src/handle/client_create.c	\
			src/handle/client_read.c	\
			src/handle/client_delete.c	\
			src/handle/client_set_nick.c	\
			src/list.c			\
			src/list_get.c			\
			src/list_push.c			\
			src/list_pop.c			\
			src/list_iter.c			\
			src/list_find.c			\

OBJ_MAIN	=	$(MAIN:.c=.o)

OBJS		=	$(SRCS:.c=.o)

TEST		=	unit_tests.out

SRCS_TEST	=	tests/test-list.c	\
			tests/test-handle_client.c \
			tests/test-manager_client.c

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

CFLAGS		=	-W -Wextra -Wall -Iinclude/

LDFLAGS		=

%.o: %.c
	@printf "[\033[0;36mcompiling\033[0m]% 39s\r" $< | tr " " "."
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf "[\033[0;32mcompiled\033[0m]% 40s\n" $< | tr " " "."

all: $(NAME)

debug: CFLAGS += -ggdb
debug: fclean
debug: $(NAME)

tests: $(TEST) $(NAME)

tests_run: CC=gcc --coverage
tests_run: tests
	@./$(TEST) -j 1 --verbose --always-succeed
	@cd tests/ && find -name "*.gcda" -delete -o -name "*.gcno" -delete
	@cd src/ && rm -f main.gcda main.gcno

$(NAME): $(OBJ_MAIN) $(OBJS)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(NAME) | tr " " "."
	@$(CC) $(OBJ_MAIN) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(NAME) | tr " " "."

$(TEST): $(OBJS_TEST)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(TEST) | tr " " "."
	@$(CC) $(OBJS_TEST) -o $(TEST) $(LDFLAGS) -lcriterion
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(TEST) | tr " " "."

clean: artifacts_clean
	@printf "[\033[0;31mdeletion\033[0m][objects]% 31s\n" `$(RM) $(OBJ_MAIN) $(OBJS) $(OBJS_TEST) | wc -l | tr -d '\n'` | tr " " "."

fclean: clean
	@$(RM) $(NAME) $(TEST) > /dev/null
	@printf "[\033[0;31mdeletion\033[0m][binary]% 32s\n" $(NAME) | tr " " "."

artifacts_clean:
	@printf "[\033[0;31mdeletion\033[0m][artifacts]% 29s\n" `find -type f \( -name "*.gcno" -o -name "*.gc*" \) -delete -print | wc -l | tr -d '\n'` | tr " " "."

re: fclean all

.PHONY: all clean fclean re debug tests tests_run clean cov_clean
