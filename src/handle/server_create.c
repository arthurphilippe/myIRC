/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** server_create
*/

#include "manager.h"
#include "handle/server.h"

int handle_server_create(manager_t *manager, int fd)
{
	handle_t *hdl = manager_handle_get_free(manager);

	hdl->h_type = H_SERVER;
	hdl->h_fd = fd;
	hdl->h_read = client_read_serv;
	hdl->h_write = NULL;
	return (MANAGER_RET_OK);
}
