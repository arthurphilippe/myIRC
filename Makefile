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

MAIN_CLIENT	=	src/client/main.c

SRCS		=

SRCS_CLIENT	=	src/client/set_server_info.c \
			src/client/error.c		\
			src/client/client.c

OBJ_MAIN	=	$(MAIN:.c=.o)

OBJ_MAIN_CLIENT	=	$(MAIN_CLIENT:.c=.o)

OBJS		=	$(SRCS:.c=.o)

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

TEST		=	unit_tests.out

SRCS_TEST	=

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

CFLAGS		=	-W -Wextra -Wall -Iinclude/

LDFLAGS		=	-L./ -lpthread -lm -lncurses

%.o: %.c
	@printf "[\033[0;36mcompiling\033[0m]% 39s\r" $< | tr " " "."
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf "[\033[0;32mcompiled\033[0m]% 40s\n" $< | tr " " "."

all: $(NAME) $(NAME_CLIENT)

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
	@printf "[\033[0;31mdeletion\033[0m][artifacts]% 29s\n" `find -type f \( -name "*.gcno" -o -name "*.gc*" -o -name "*.html" \) -delete -print | wc -l | tr -d '\n'` | tr " " "."

re: fclean all

.PHONY: all clean fclean re debug tests tests_run clean cov_clean