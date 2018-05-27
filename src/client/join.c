/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** join
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "client/client.h"
#include "manager.h"
#include "stolist.h"

int client_cmd_join(manager_t *manager, char *arg)
{
	list_t *list = stolist(arg, " ");
	client_t *client = manager->m_data;
	list_iter_t *iterator = list_iter_create(list, FWD);
	char *str = NULL;

	if (!list || !iterator || client->state == NOT_CONNECTED) {
		return (ret_int_client(RET_ERR, "Command join", "failed", ""));
	}
	if (strlen(str = list_iter_access(iterator))
		&& (str[0] == '#' || str[0] == '&')) {
		client_cmd_part(manager, client->channel);
		dprintf(client->fd, "%s %s\r\n", "JOIN", str);
		strcpy(client->channel, str);
	}
	free(iterator);
	list_destroy(list);
	return (0);
}
