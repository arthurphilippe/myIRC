/*
** EPITECH PROJECT, 2018
** Client IRC
** File description:
** IRC Core Func
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <client/client.h>

client_t *client_set_connection(char *cmd)
{
	client_t *client = NULL;

	if ((client = client_check_connect_serv(cmd))) {
		return (client);
	} else {
		if (client != NULL)
			free(client);
		ret_null_error("Client ", "not connected", " to a server");
	}
	return (client);
}

client_t *client_basic_info_loop(manager_t *manager, handle_t *hdl)
{
	client_t *client;
	int len = 0;
	char buf[4096];

	memset(buf, '\0', 4096);
	if ((len = read(hdl->h_fd, buf, 4096)) == -1)
		return (NULL);
	if (len > 0)
		remove_carriage_ret(buf);
	if ((client = client_set_connection(buf)) != NULL) {
		manager->m_data = client;
		manager_set_irc_socket(manager, client->fd);
		return (manager->m_data);
	}
	return (NULL);
}

static int client_irc_process(manager_t *manager, handle_t *hdl)
{
	(void) manager;
	int len = 0;
	char buf[4096];
	client_t *client = manager->m_data;

	memset(buf, '\0', 4096);
	if ((len = read(hdl->h_fd, buf, 4096)) == -1)
		return (RET_ERR);
	if (len > 0)
		remove_carriage_ret(buf);
	dprintf(client->fd, "%s\r\n", buf);
	return (0);
}

void client_irc(manager_t *manager, handle_t *hdl)
{
	if (manager->m_data == NULL)
		client_basic_info_loop(manager, hdl);
	else
		client_irc_process(manager, hdl);
}
