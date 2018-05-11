/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** user
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "client/client.h"

int client_cmd_user(manager_t *manager, char *arg)
{
	client_t *client = manager->m_data;

	strcpy(client->nickname, arg);
	if (strlen(client->nickname) > 0) {
		dprintf(client->fd, "%s %s %s %s\r\n", "USER",
			"LOCAL_COMPUTER", client->serv_ip, arg);
	}
	return (0);
}
