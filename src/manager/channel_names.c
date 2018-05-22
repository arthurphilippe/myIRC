/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_users_list
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "manager.h"
#include "server.h"
#include "list.h"
#include "handle/client.h"

void manager_channel_names_by_name(manager_t *manager, handle_t *client,
					const char *chan_name)
{
	channel_t *chan = manager_channel_find(manager, chan_name);

	if (!chan)
		return;
	manager_channel_names(chan, client);
}

void manager_channel_names(channel_t *chan, handle_t *client)
{
	list_iter_t *iter = list_iter_create(chan->ch_clients, FWD);
	handle_client_t *data = client->h_data;
	handle_client_t *memb_data;
	handle_t *member;

	if (!iter)
		return;
	while ((member = list_iter_access(iter))) {
		memb_data = member->h_data;
		dprintf(client->h_fd, ":myirc_serv 353 %s = %s :%s\n\r",
			data->hc_nick, chan->ch_name, memb_data->hc_nick);
		list_iter_next(iter);
	}
	free(iter);
	dprintf(client->h_fd,
		":myirc_serv 366 %s %s :End of /NAMES list.\n\r",
		data->hc_nick, chan->ch_name);
}
