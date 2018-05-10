/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_join
*/

#include <stdlib.h>
#include <string.h>
#include "manager.h"
#include "server.h"

int manager_channel_join_by_name(manager_t *manager,
					const char *chanstr,
					handle_t *client)
{
	server_t *serv = manager->m_data;
	list_iter_t *iter = list_iter_create(serv->sv_channels, FWD);
	channel_t *chan;

	while ((chan = list_iter_access(iter))
		&& strcmp(chan->ch_name, chanstr) != 0) {
		list_iter_next(iter);
	}
	free(iter);
	if (chan)
		return (manager_channel_join(chan, client));
	return (-1);
}

int manager_channel_join(channel_t *channel, handle_t *client)
{
	return (list_push_back(channel->ch_clients, client));
}
