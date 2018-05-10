/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client_create
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"
#include "handle/client.h"
#include "server.h"

static void init_data(handle_client_t *data)
{
	data->hc_nick = strdup("anon");
	data->hc_channels = list_create(NULL);
}

int handle_client_create(manager_t *manager, int sock)
{
	handle_t *hdl = manager_handle_get_free(manager);

	if (!hdl) {
		close(sock);
		return (MANAGER_RET_ERR);
	}
	hdl->h_data = malloc(sizeof(handle_client_t));
	if (!hdl->h_data) {
		close(sock);
		return (MANAGER_RET_ERR);
	}
	init_data(hdl->h_data);
	hdl->h_fd = sock;
	hdl->h_type = H_CLIENT;
	hdl->h_read = handle_client_read;
	manager_client_add(manager, hdl);
	return (MANAGER_RET_OK);
}
