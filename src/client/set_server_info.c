/*
** EPITECH PROJECT, 2018
** Client FTP
** File description:
** set structure
*/

#include <string.h>
#include <stdlib.h>
#include "client/client.h"

client_t	*client_set_server_info(char *arg)
{
	client_t *new_client = malloc(sizeof(client_t));
	char *tmp;

	if (!new_client)
		return (ret_null_error("malloc: ", MALLOC_FAIL, NULL));
	memset(new_client, '\0', sizeof(client_t));
	tmp = extract_cmd_arg(arg, ":");
	if (tmp == NULL)
		new_client->port = 6667;
	else {
		new_client->port = atoi(tmp);
		free(tmp);
	}
	if (new_client->port == 0)
		return (ret_null_error("atoi failed: ", ARG2_FAIL, NULL));
	new_client->serv_ip = extract_command(arg, ":");
	return (new_client);
}
