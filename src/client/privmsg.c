/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** privmsg
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "client/client.h"
#include "manager.h"

int client_cmd_privmsg(manager_t *manager, char *arg)
{
	client_t *client = manager->m_data;

	if (!client || client->state != CONNECTED || !arg) {
		return (ret_int_client(0, "Client", "not connected",
							"to a server"));
	}
	if (strlen(client->channel))
		dprintf(client->fd, "PRIVMSG %s :%s\n\r",
					client->channel ,arg);
	else {
		free(arg);
		return (ret_int_client(0, "Client", "not connected",
							"to a channel"));
	}
	free(arg);
	return (0);
}
