/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** add_client
*/

#include <stdlib.h>
#include "manager.h"
#include "server.h"

int manager_client_add(manager_t *manager, handle_t *client)
{
	server_t *serv = manager->m_data;

	return (list_push_back(serv->sv_clients, client));
}

static void rm_from_all_channel(list_t *channels, handle_t *client)
{
	list_iter_t *iter;
	for (iter = list_iter_create(channels, FWD);
		iter && list_iter_access(iter); list_iter_next(iter)) {
		manager_channel_leave(list_iter_access(iter), client);
	}
	free(iter);
}

void manager_client_remove(manager_t *manager, handle_t *client)
{
	server_t *serv = manager->m_data;
	list_iter_t *iter = list_find_addr(serv->sv_clients, client);

	rm_from_all_channel(serv->sv_channels, client);
	if (iter) {
		list_erase(iter);
		free(iter);
	}
}
