/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** users
*/

#include <stdio.h>
#include "client/client.h"
#include "manager.h"

int client_cmd_users(manager_t *manager, char *arg)
{
	client_t *client = manager->m_data;

	(void) arg;
	dprintf(client->fd, "USERS\r\n");
	return (0);
}
