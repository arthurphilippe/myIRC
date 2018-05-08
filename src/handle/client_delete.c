/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client_delete
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "manager.h"
#include "handle/client.h"

void handle_client_delete(manager_t *manager, handle_t *client_hdl)
{
	handle_client_t *data = client_hdl->h_data;

	printf("%d: Connection closed\n", client_hdl->h_fd);
	close(client_hdl->h_fd);
	client_hdl->h_type = H_FREE;
	free(data->hc_nickname);
	list_destroy(data->hc_channels);
	free(data);
	manager->m_live = false;
}
