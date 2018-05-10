/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** delete_connect
*/

#include <stdlib.h>
#include "handle/server.h"
#include "client/client.h"

void manager_delete_connect(manager_t *manager)
{
	client_t *client = manager->m_data;

	if (client) {
		free(client->serv_ip);
		free(client);
	}
}
