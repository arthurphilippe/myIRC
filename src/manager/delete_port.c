/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** delete_port
*/

#include <stdlib.h>
#include "handle/server.h"
#include "handle/client.h"
#include "manager.h"
#include "server.h"

void manager_delete_port(manager_t *manager)
{
	server_t *serv = manager->m_data;

	for (unsigned int i = 0; i < MAX_HANDLES; i++) {
		if (manager->m_handles[i].h_type == H_CLIENT)
			handle_client_delete(manager, &manager->m_handles[i]);
	}
	list_destroy(serv->sv_channels);
	list_destroy(serv->sv_clients);
	free(serv);
}
