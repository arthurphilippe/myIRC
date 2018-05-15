/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_list
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "manager.h"
#include "server.h"
#include "list.h"
#include "handle/client.h"

void manager_channel_list(manager_t *manager, handle_t *hdl,
				const char *matchstr)
{
	server_t *serv = manager->m_data;
	list_iter_t *iter = list_iter_create(serv->sv_channels, FWD);
	channel_t *chan;
	handle_client_t *data = hdl->h_data;

	while ((chan = list_iter_next(iter))) {
		if (strlen(matchstr) || strstr(chan->ch_name, matchstr)) {
			dprintf(hdl->h_fd, ":myirc_serv 322 %s %s 1 :%s\r\n",
				data->hc_nick, chan->ch_name, chan->ch_name);
		}
	}
	free(iter);
}
