/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client_read
*/

#include <unistd.h>
#include <stdio.h>
#include "manager.h"

void handle_client_read(manager_t *manager, handle_t *client_hdl)
{
	int r;
	char buf[4096];

	(void) manager;
	r = read(client_hdl->h_fd, buf, 4096);
	if (r > 0)
	{
		buf[r] = '\0';
		printf("%d: %s\n", client_hdl->h_fd, buf);
	} else {
		printf("%d: Connection closed\n", client_hdl->h_fd);
		close(client_hdl->h_fd);
		client_hdl->h_type = H_FREE;
	}
}
