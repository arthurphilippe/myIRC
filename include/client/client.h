/*
** EPITECH PROJECT, 2018
** Client IRC
** File description:
** Header
*/

#ifndef CLIENT_H_
	#define CLIENT_H_

	#include <stdbool.h>
	#include "client_error.h"
	#include "manager.h"
	#include "cmd.h"

	#define RET_ERR (-1)
	#define ANSI_COLOR_RED		"\x1b[31m"
	#define ANSI_COLOR_GREEN	"\x1b[32m"
	#define ANSI_COLOR_YELLOW	"\x1b[33m"
	#define ANSI_COLOR_BLUE		"\x1b[34m"
	#define ANSI_COLOR_MAGENTA	"\x1b[35m"
	#define ANSI_COLOR_CYAN		"\x1b[36m"
	#define ANSI_COLOR_RESET	"\x1b[0m"

typedef enum e_state {
	NOT_CONNECTED,
	CONNECTED,
	UNK_STATE,
}		state_t;

typedef struct s_cmd {
	char *cmd_name;
	state_t state;
	int (*ptr)(manager_t *, char *);
}		cmd_t;

typedef struct	s_client {
	char	*serv_ip;
	char	nickname[CMD_MAX_SIZE];
	char	username[CMD_MAX_SIZE];
	int	port;
	int	fd;
	state_t state;
}		client_t;

/*
**	Client commands
*/
int client_cmd_quit(manager_t *manager, char *arg);
int client_cmd_nick(manager_t *manager, char *arg);
int client_cmd_user(manager_t *manager, char *arg);
int client_cmd_run(manager_t *manager, const char *cmd);

/*
**	Client automatic answer
*/
int client_cmd_answer(manager_t *manager, const char *cmd);
int client_cmd_pong(manager_t *manager, char *arg);


/*
**	Sides Functions
*/
int ret_int_error(int ret, const char *msg, const char *what, const char *end);
void *ret_null_error(const char *msg, const char *what, const char *end);

#endif /* !CLIENT_H_ */
