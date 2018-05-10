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
}		state_t;

typedef struct	s_client {
	char	*serv_ip;
	int	port;
	int	fd;
	state_t state;
}		client_t;

/*
**	Sides Functions
*/
int ret_int_error(int ret, const char *msg, const char *what, const char *end);
void *ret_null_error(const char *msg, const char *what, const char *end);

#endif /* !CLIENT_H_ */
