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
**	Client IRC Core Function
*/
client_t	*client_set_connection(char *cmd);
client_t	*client_basic_info_loop(manager_t *manager, handle_t *hdl);
client_t	*client_set_server_info(char *arg);
void client_irc(manager_t *manager, handle_t *hdl);
void		remove_carriage_ret(char *str);
char		*extract_cmd_arg(char *cmd, const char *delim);
char		*extract_command(char *str, const char *delim);
client_t	*client_check_connect_serv(char *user_cmd);
manager_t	*manager_create_connect();

/*
**	Sides Functions
*/
int ret_int_error(int ret, const char *msg, const char *what, const char *end);
void *ret_null_error(const char *msg, const char *what, const char *end);

#endif /* !CLIENT_H_ */
