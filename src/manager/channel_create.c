/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_create
*/

#include "manager.h"
#include "server.h"

int manager_channel_create(manager_t *manager, const char *name)
{
	server_t *serv = manager->m_data;
	channel_t *chan = malloc(sizeof(channel_t));

	if (!chan)
		return (-1);
	chan->ch_name = strdup(name);
	if (!chan->ch_name) {
		free(chan);
		return (-1);
	}
	chan->ch_clients = list_create(NULL);
	if (!chan->ch_clients) {
		free(chan->ch_name);
		free(chan);
		return (-1);
	}
	return (list_push_back(serv->sv_channels, chan));
}
