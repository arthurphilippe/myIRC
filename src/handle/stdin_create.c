/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** stdin_create
*/

#include <unistd.h>
#include "manager.h"
#include "handle/server.h"

int handle_stdin_create(manager_t *manager)
{
	handle_t *hdl = manager_handle_get_free(manager);

	if (!hdl)
		return (MANAGER_RET_ERR);
	hdl->h_fd = STDIN_FILENO;
	hdl->h_type = H_STDIN;
	hdl->h_read = handle_stdin_read;
	hdl->h_write = NULL;
	return (MANAGER_RET_OK);
}
