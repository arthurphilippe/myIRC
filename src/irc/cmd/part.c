/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** part
*/

#include <stdlib.h>
#include <stdio.h>
#include "irc/cmd.h"
#include "handle/client.h"
#include "server.h"
#include "stolist.h"

static void irc_cmd_part_extract(manager_t *manager, handle_t *hdl,
					const char *arg)
{
	list_t *channel_names = stolist(arg, ",");
	list_iter_t *iter;
	char *chan_name;

	if (!channel_names)
		return;
	iter = list_iter_create(channel_names, FWD);
	if (!iter)
		return;
	while ((chan_name = list_iter_access(iter))) {
		manager_channel_leave_by_name(manager, hdl, chan_name);
		list_iter_next(iter);
	}
	free(iter);
	list_destroy(channel_names);
}

void irc_cmd_part(manager_t *manager, handle_t *hdl, list_t *arg)
{
	handle_client_t *client = hdl->h_data;

	if (arg->l_size < 1)
		dprintf(hdl->h_fd, "461 %s PART :Not enough parameters\r\n",
			client->hc_nick);
	else
		irc_cmd_part_extract(manager, hdl, arg->l_start->n_data);
}
