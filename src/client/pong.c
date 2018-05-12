/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** pong
*/

#include <stdio.h>
#include "client/client.h"

int client_cmd_pong(manager_t *manager, char *arg)
{
	client_t *client = manager->m_data;

	dprintf(client->fd, "%s %s\r\n", "PONG", arg);
	dprintf(1, "%s%s%s %s %s", ANSI_COLOR_MAGENTA,
			"Client::", ANSI_COLOR_RESET, "PONG", arg);
	return (0);
}
