/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client_set_nick
*/

#include <string.h>
#include <stdlib.h>
#include "manager.h"
#include "handle/client.h"

int handle_client_set_nick(handle_t *client_hdl,
				const char *nick)
{
	handle_client_t *data = client_hdl->h_data;

	free(data->hc_nick);
	data->hc_nick = strdup(nick);
	if (!data->hc_nick)
		return (-1);
	return (0);
}
