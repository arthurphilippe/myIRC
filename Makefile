##
## EPITECH PROJECT, 2018
## nm
## File description:
## Makefile
##

CC		=	gcc

RM		=	rm -vf

NAME_CLIENT	=	client

NAME		=	server

MAIN		=	src/main.c

SRCS		=	src/manager/create.c		\
			src/manager/create_port.c	\
			src/manager/delete_port.c	\
			src/manager/handle_get.c	\
			src/manager/loop.c		\
			src/manager/delete.c		\
			src/manager/channel_join.c	\
			src/manager/channel_leave.c	\
			src/manager/channel_destroy.c	\
			src/manager/channel_create.c	\
			src/manager/channel_find.c	\
			src/manager/channel_names.c	\
			src/manager/channel_list.c	\
			src/manager/channel_send_msg.c	\
			src/manager/client.c		\
			src/handle/port_read.c		\
			src/handle/port_create.c	\
			src/handle/client_create.c	\
			src/handle/client_read.c	\
			src/handle/client_delete.c	\
			src/handle/client_set_nick.c	\
			src/handle/client_find.c	\
			src/irc/cmd_get_name.c		\
			src/irc/cmd_strip_to_args.c	\
			src/irc/cmd_run.c		\
			src/irc/cmd/user.c		\
			src/irc/cmd/nick.c		\
			src/irc/cmd/part.c		\
			src/irc/cmd/names.c		\
			src/irc/cmd/list.c		\
			src/irc/cmd/privmsg.c		\
			src/irc/msg/welcome.c		\
			src/irc/msg/client.c		\
			src/list.c			\
			src/list_get.c			\
			src/list_push.c			\
			src/list_pop.c			\
			src/list_iter.c			\
			src/list_find.c			\
			src/stolist.c			\
			src/irc/cmd/join.c

MAIN_CLIENT	=	src/client/main.c

SRCS_CLIENT	=	src/manager/connect_to_server.c \
			src/manager/create.c		\
			src/manager/create_connect.c	\
			src/manager/delete_connect.c	\
			src/manager/handle_get.c	\
			src/manager/delete.c		\
			src/client/error.c		\
			src/client/command.c		\
			src/handle/server_create.c	\
			src/handle/stdin_create.c	\
			src/handle/stdin_read.c		\
			src/manager/loop.c		\
			src/client/read_server.c	\
			src/client/cmd_run.c		\
			src/client/nick.c		\
			src/client/pong.c		\
			src/client/answer_serv.c	\
			src/client/quit.c		\
			src/client/join.c		\
			src/stolist.c			\
			src/list.c			\
			src/list_get.c			\
			src/list_push.c			\
			src/list_pop.c			\
			src/list_iter.c			\
			src/list_find.c			\
			src/client/part.c		\
			src/client/list.c		\
			src/client/names.c		\
			src/client/privmsg.c		\
			src/client/users.c		\
			src/client/msg.c		\

OBJ_MAIN	=	$(MAIN:.c=.o)

OBJ_MAIN_CLIENT	=	$(MAIN_CLIENT:.c=.o)

OBJS		=	$(SRCS:.c=.o)

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

TEST		=	unit_tests.out

SRCS_TEST	=	tests/test-list.c	\
			tests/test-handle_client.c \
			tests/test-manager_client.c	\
			tests/test-manager_channel.c	\
			tests/test-stolist.c		\
			tests/test-irc_cmd.c

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

CFLAGS		=	-W -Wextra -Wall -Iinclude/

LDFLAGS		=

%.o: %.c
	@printf "[\033[0;36mcompiling\033[0m]% 39s\r" $< | tr " " "."
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf "[\033[0;32mcompiled\033[0m]% 40s\n" $< | tr " " "."

all: $(NAME) $(NAME_CLIENT)

debug: CFLAGS += -ggdb
debug: fclean
debug: $(NAME) $(NAME_CLIENT)

tests: CFLAGS += -ggdb
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

$(NAME_CLIENT): $(OBJ_MAIN_CLIENT) $(OBJS_CLIENT)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(NAME_CLIENT) | tr " " "."
	@$(CC) $(OBJ_MAIN_CLIENT) $(OBJS_CLIENT) $(LDFLAGS) -o $(NAME_CLIENT)
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(NAME_CLIENT) | tr " " "."

$(TEST): $(OBJS_TEST)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(TEST) | tr " " "."
	@$(CC) $(OBJS_TEST) -o $(TEST) $(LDFLAGS) -lcriterion
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(TEST) | tr " " "."

clean: artifacts_clean
	@printf "[\033[0;31mdeletion\033[0m][objects]% 31s\n" `$(RM) $(OBJ_MAIN) $(OBJS) $(OBJS_TEST) $(OBJ_MAIN_CLIENT) $(OBJS_CLIENT)| wc -l | tr -d '\n'` | tr " " "."

fclean: clean
	@$(RM) $(NAME) $(TEST) > /dev/null
	@$(RM) $(NAME_CLIENT) $(TEST) > /dev/null
	@printf "[\033[0;31mdeletion\033[0m][binary]% 32s\n" $(NAME) | tr " " "."
	@printf "[\033[0;31mdeletion\033[0m][binary]% 32s\n" $(NAME_CLIENT) | tr " " "."

artifacts_clean:
	@printf "[\033[0;31mdeletion\033[0m][artifacts]% 29s\n" `find -type f \( -name "*.gcno" -o -name "*.gc*" \) -delete -print | wc -l | tr -d '\n'` | tr " " "."

re: fclean all

.PHONY: all clean fclean re debug tests tests_run clean cov_clean
