/*
** EPITECH PROJECT, 2018
** Client FTP
** File description:
** set structure
*/

#include <string.h>
#include <stdlib.h>
#include "client/client.h"

client_t	*client_set_server_info(char *command)
{
	client_t *new_client = malloc(sizeof(client_t));
	char **av;

	if (!new_client)
		return (ret_null_error("malloc: ", MALLOC_FAIL, NULL));
	memset(new_client, '\0', sizeof(client_t));
	new_client->port = atoi(av[2]);
	if (new_client->port == 0)
		return (ret_null_error(av[2], ARG2_FAIL, NULL));
	strcpy(new_client->serv_ip, av[1]);
	return (new_client);
}
