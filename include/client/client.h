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

	#define RET_ERR (-1)

typedef struct	s_client {
	char	serv_ip[1024];
	int	port;
}		client_t;

/*
**	Client IRC Core Function
*/
client_t	*client_set_server_info(int ac, char **av);
int		client_irc(client_t *);

/*
**	Sides Functions
*/
int ret_int_error(int ret, const char *msg, const char *what, const char *end);
void *ret_null_error(const char *msg, const char *what, const char *end);

#endif /* !CLIENT_H_ */
