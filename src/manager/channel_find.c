/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_list
*/

#include <stdlib.h>
#include <string.h>
#include "manager.h"
#include "server.h"
#include "list.h"

channel_t *manager_channel_find(manager_t *manager, const char *str)
{
	server_t *serv = manager->m_data;
	list_iter_t *iter = list_iter_create(serv->sv_channels, FWD);
	channel_t *chan;

	while ((chan = list_iter_access(iter))
		&& strcmp(chan->ch_name, str) != 0) {
		list_iter_next(iter);
	}
	free(iter);
	return (chan);
}
