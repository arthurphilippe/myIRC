/*
** EPITECH PROJECT, 2018
** Client IRC
** File description:
** IRC Core Func
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <client/client.h>

client_t *client_set_connection(char *cmd)
{
	client_t *client = NULL;

	if ((client = client_check_connect_serv(cmd))
			&& client->state == CONNECTED) {
		printf("%s\n", client->serv_ip);
		return (client);
	} else {
		if (client != NULL)
			free(client);
		dprintf(2, "%s\n", CLIENT_NOT_CONNECTED);
	}
	return (client);
}

client_t *client_basic_info_loop(manager_t *manager, handle_t *hdl)
{
	int len = 0;
	char buf[4096];

	if ((len = read(hdl->h_fd, buf, 4096)) == -1)
		return (NULL);
	remove_carriage_ret(buf);
	if ((manager->m_data = client_set_connection(buf)) != NULL) {
		return (manager->m_data);
	}
	return (NULL);
}

static int client_irc_process(manager_t *manager)
{
	(void) manager;
	return (0);
}

void client_irc(manager_t *manager, handle_t *hdl)
{
	if (manager->m_data == NULL)
		client_basic_info_loop(manager, hdl);
	else
		client_irc_process(manager);
}
