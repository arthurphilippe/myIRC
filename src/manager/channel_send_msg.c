/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_send_msg
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "manager.h"
#include "server.h"
#include "handle/client.h"
#include "irc/msg.h"

void manager_channel_send_msg(channel_t *chan, const char *msg,
				const char *dest)
{
	list_iter_t *iter = list_iter_create(chan->ch_clients, FWD);
	handle_t *hdl;

	if (!iter)
		return;
	while ((hdl = list_iter_next(iter))) {
		irc_msg_client(hdl, msg, dest);
	}
	free(iter);
}
