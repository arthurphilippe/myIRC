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

static void offline_cmd(manager_t *manager, const char *cmd)
{
	char *cmd_name = client_cmd_extract_name(cmd, CMD_MAIN_DELIM);

	if (cmd_name && !strcmp(cmd_name, USER_CMD_SERVER)) {
		// handle_server_create(manager,
		// 	client_cmd_extract_arg(cmd, CMD_MAIN_DELIM));
		manager_connect_to_server(manager,
			client_cmd_extract_arg(cmd, CMD_MAIN_DELIM));
	}
	free(cmd_name);
}

void handle_stdin_read(manager_t *manager, handle_t *hdl)
{
	int len = 0;
	char buff[CMD_MAX_SIZE];
	client_t *client = manager->m_data;

	memset(buff, 0, CMD_MAX_SIZE);
	if ((len = read(hdl->h_fd, buff, CMD_MAX_SIZE)) == -1)
		return;
	if (!len)
		manager->m_live = false;
	rm_crlf(buff);
	if (manager->m_data == NULL) {
		offline_cmd(manager, buff);
	} else {
		dprintf(client->fd, "%s\r\n", buff);
	}
}
