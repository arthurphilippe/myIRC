/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** list
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "irc/cmd.h"
#include "irc/msg.h"
#include "server.h"
#include "handle/client.h"

static void list_extract(manager_t *manager, handle_t *hdl, list_t *arg)
{
	list_iter_t *iter = list_iter_create(arg, FWD);
	char *tmp;

	if (!iter)
		return;
	while ((tmp = list_iter_next(iter))) {
		manager_channel_list(manager, hdl, tmp);
	}
	free(iter);
}

void irc_cmd_list(manager_t *manager, handle_t *hdl, list_t *arg)
{
	handle_client_t *data = hdl->h_data;

	dprintf(hdl->h_fd, ":myirc_serv 321 %s Channel :Visible Name\r\n",
		data->hc_nick);
	if (!arg->l_size)
		manager_channel_list(manager, hdl, "");
	else
		list_extract(manager, hdl, arg);
	dprintf(hdl->h_fd, ":myirc_serv 323 %s :End of /LIST\r\n",
		data->hc_nick);

}
