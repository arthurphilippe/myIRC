/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client_find
*/

#include <stdlib.h>
#include <string.h>
#include "manager.h"
#include "handle/client.h"
#include "server.h"
#include "list.h"

handle_t *handle_client_find(manager_t *manager, const char *name)
{
	server_t *serv = manager->m_data;
	list_iter_t *iter = list_iter_create(serv->sv_clients, FWD);
	handle_t *hdl;
	handle_client_t *data;

	if (!iter)
		return (NULL);
	while ((hdl = list_iter_next(iter))) {
		data = hdl->h_data;
		if (!strcmp(name, data->hc_nick)) {
			free(iter);
			return (hdl);
		}
	}
	free(iter);
	return (NULL);
}
