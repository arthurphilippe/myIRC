/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_join
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "manager.h"
#include "server.h"
#include "handle/client.h"

static void debug_show_members(channel_t *channel)
{
	list_iter_t *iter = list_iter_create(channel->ch_clients, FWD);
	handle_t *client;
	handle_client_t *data;

	while (list_iter_access(iter)) {
		client = list_iter_access(iter);
		data = client->h_data;
		printf("debug %s\n", data->hc_nick);
		list_iter_next(iter);
	}
	free(iter);
}

static channel_t *create_channel(manager_t *manager, server_t *serv,
					const char *chanstr)
{
	list_iter_t *iter;
	channel_t *chan;

	if (manager_channel_create(manager, chanstr))
		return (NULL);
	iter = list_iter_create(serv->sv_channels, FWD);
	if (!iter)
		return (NULL);
	while ((chan = list_iter_access(iter))) {
		if (!strcmp(chan->ch_name, chanstr)) {
			free(iter);
			return (chan);
		}
		list_iter_next(iter);
	}
	free(iter);
	return (chan);
}

int manager_channel_join_by_name(manager_t *manager, const char *chanstr,
					handle_t *client)
{
	channel_t *chan = manager_channel_find(manager, chanstr);
	server_t *serv = manager->m_data;

	if (!chan)
		chan = create_channel(manager, serv, chanstr);
	if (chan) {
		int ret = manager_channel_join(chan, client);
		debug_show_members(chan);
		return (ret);
	}
	return (-1);
}

int manager_channel_join(channel_t *channel, handle_t *client)
{
	list_iter_t *member = list_find_addr(channel->ch_clients, client);
	handle_client_t *data = client->h_data;
	int ret = -1;

	if (!member) {
		list_push_back(data->hc_channels, channel);
		ret = list_push_back(channel->ch_clients, client);
		manager_channel_join_notify(channel, client);
	}
	free(member);
	return (ret);
}
