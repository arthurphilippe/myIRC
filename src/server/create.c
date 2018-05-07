/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

server_t *server_create()
{
	server_t *serv = malloc(sizeof(server_t));

	if (!serv)
		return (NULL);
	memset(serv->sv_handles, 0, MAX_HANDLES * sizeof(handle_t));
	return (serv);
}

server_t *server_create_port(int port)
{
	server_t *serv = server_create();

	if (!serv)
		return (NULL);
	server_port_listen(serv, port);
	return (serv);
}
