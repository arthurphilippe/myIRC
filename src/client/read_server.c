/*
** EPITECH PROJECT, 2018
** MyIRC
** File description:
** ReadServ
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "client/client.h"

void client_read_serv(manager_t *manager, handle_t *client_hdl)
{
	int r;
	char buf[4096];

	memset(buf, '\0', 4096);
	(void) manager;
	if ((r = read(client_hdl->h_fd, buf, 4096)) <= 0) {
		/* Delete something **/
		printf(ANSI_COLOR_BLUE"EXIT\n"ANSI_COLOR_RESET);
		exit(44);
		return;
	}
	dprintf(1,
			ANSI_COLOR_GREEN"Server:: "ANSI_COLOR_RESET"%s",
									buf);
}
