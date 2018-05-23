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
				const char *dest, handle_t *client_hdl)
{
	list_iter_t *iter = list_iter_create(chan->ch_clients, FWD);
	handle_client_t *client = client_hdl->h_data;
	handle_t *hdl;

	if (!iter)
		return;
	while ((hdl = list_iter_next(iter))) {
		irc_msg_client(hdl, msg, dest, client->hc_nick);
	}
	free(iter);
}

void manager_channel_join_notify(channel_t *chan, handle_t *client_hdl)
{
	handle_client_t *client = client_hdl->h_data;
	list_iter_t *iter = list_iter_create(chan->ch_clients, FWD);
	handle_t *hdl;

	if (!iter)
		return;
	while ((hdl = list_iter_next(iter))) {
		dprintf(hdl->h_fd, ":%s!%s@127.0.0.1.IP JOIN :%s\r\n",
			client->hc_nick, client->hc_realname,
			chan->ch_name);
	}
	free(iter);
}

void manager_channel_nick_notify(channel_t *chan, handle_t *client_hdl,
					const char *new_nick)
{
	handle_client_t *client = client_hdl->h_data;
	list_iter_t *iter = list_iter_create(chan->ch_clients, FWD);
	handle_t *hdl;

	if (!iter)
		return;
	while ((hdl = list_iter_next(iter))) {
		dprintf(hdl->h_fd, ":%s!%s@127.0.0.1.IP NICK %s\r\n",
			client->hc_nick, client->hc_realname, new_nick);
	}
	free(iter);

}
