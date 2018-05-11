/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** nick
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "client/client.h"

int client_cmd_nick(manager_t *manager, char *arg)
{
	client_t *client = manager->m_data;

	if (!arg || strlen(arg )< 1)
		return (ret_int_client(0, "USAGE: /nick", "$nickname", ""));
	strcpy(client->nickname, arg);
	strcpy(client->username, arg);
	if (client->fd > 0) {
		dprintf(client->fd, "%s %s\r\n", "NICK", arg);
		dprintf(client->fd, "%s %s %s %s %s\r\n", "USER",
			arg, "LOCAL_COMPUTER", client->serv_ip, arg);
		client->state = CONNECTED;
	}
	return (0);
}
