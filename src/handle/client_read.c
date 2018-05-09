/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client_read
*/

#include <unistd.h>
#include <stdio.h>
#include "manager.h"
#include "handle/client.h"

void handle_client_read(manager_t *manager, handle_t *client_hdl)
{
	int r;
	char buf[4096];
	handle_client_t *data = client_hdl->h_data;

	r = read(client_hdl->h_fd, buf, 4096);
	if (r > 0)
	{
		buf[r] = '\0';
		printf("%s: %s\n", data->hc_nickname, buf);
	} else {
		handle_client_delete(manager, client_hdl);
	}
}
