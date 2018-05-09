/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_leave
*/

#include <stdlib.h>
#include "manager.h"
#include "server.h"

void manager_channel_leave(channel_t *channel, handle_t *client)
{
	list_iter_t *iter = list_find_addr(channel->ch_clients, client);

	if (iter) {
		list_erase(iter);
		free(iter);
	}
}
