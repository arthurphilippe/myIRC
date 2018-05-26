/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_leave
*/

#include <stdlib.h>
#include "manager.h"
#include "server.h"
#include "handle/client.h"

void manager_channel_leave(channel_t *channel, handle_t *client)
{
	list_iter_t *iter = list_find_addr(channel->ch_clients, client);
	handle_client_t *data = client->h_data;

	if (iter) {
		manager_channel_part_notify(channel, client);
		list_erase(iter);
		free(iter);
	}
	iter = list_find_addr(data->hc_channels, channel);
	if (iter) {
		list_erase(iter);
		free(iter);
	}
}

void manager_channel_leave_by_name(manager_t *manager, handle_t *client,
					const char *chan_name)
{
	channel_t *chan = manager_channel_find(manager, chan_name);

	if (chan) {
		manager_channel_leave(chan, client);
	}
}
