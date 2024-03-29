/*
** EPITECH PROJECT, 2018
** MyIRC
** File description:
** ReadServ
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "client/client.h"

/*
** Need to change this soon
** the function should delete allocated memory
*/
void client_read_serv(manager_t *manager, handle_t *client_hdl)
{
	int r;
	char buf[4096];

	memset(buf, '\0', 4096);
	(void) manager;
	if ((r = read(client_hdl->h_fd, buf, 4096)) <= 0) {
		printf(ANSI_COLOR_BLUE"EXIT\n"ANSI_COLOR_RESET);
		manager->m_live = false;
		return;
	}
	buf[r] = '\0';
	dprintf(1, ANSI_COLOR_GREEN"Server:: "ANSI_COLOR_RESET"%s", buf);
	if (strlen(buf) > 0 && strlen(buf) < CMD_MAX_SIZE)
		client_cmd_answer(manager, buf);
}
