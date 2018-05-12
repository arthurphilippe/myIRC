/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** stdin_read
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "manager.h"
#include "client/cmd.h"
#include "handle/server.h"
#include "client/client.h"

static void rm_crlf(char *str)
{
	unsigned int i = strlen(str);

	if (i > 0 && str[i - 1] == '\n')
		str[i - 1] = '\0';
}

void handle_stdin_read(manager_t *manager, handle_t *hdl)
{
	int len = 0;
	char buff[CMD_MAX_SIZE];

	memset(buff, 0, CMD_MAX_SIZE);
	if ((len = read(hdl->h_fd, buff, CMD_MAX_SIZE)) == -1)
		return;
	if (!len)
		manager->m_live = false;
	rm_crlf(buff);
	client_cmd_run(manager, buff);
}
