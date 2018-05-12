/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client_read
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"
#include "handle/client.h"
#include "irc/cmd.h"
#include "stolist.h"

static void fill_cmd_buff(handle_client_t *client, char *buff)
{
	if (!client->hc_cmd_buff)
		return;
	stolist_existing(client->hc_cmd_buff, buff, "\n");
}

static void send_buffed_cmds(manager_t *manager, handle_t *client_hdl,
				handle_client_t *client)
{
	char *tmp;

	while (client->hc_cmd_buff->l_size) {
		tmp = client->hc_cmd_buff->l_start->n_data;
		if (tmp)
			irc_cmd_run(manager, client_hdl, tmp);
		list_pop_front(client->hc_cmd_buff);
	}
}

void handle_client_read(manager_t *manager, handle_t *client_hdl)
{
	int r;
	char buf[512];
	handle_client_t *data = client_hdl->h_data;

	r = read(client_hdl->h_fd, buf, 512);
	if (r > 0)
	{
		buf[r] = '\0';
		printf("%s: %s\n", data->hc_nick, buf);
		fill_cmd_buff(data, buf);
		if (!strncmp("QUIT", buf, 4))
			handle_client_delete(manager, client_hdl);
		else
			send_buffed_cmds(manager, client_hdl, data);
	} else {
		handle_client_delete(manager, client_hdl);
	}
}
