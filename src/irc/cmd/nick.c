/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** nick
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "irc/cmd.h"
#include "irc/msg.h"
#include "handle/client.h"
#include "server.h"

static void notify_all_chans(handle_t *hdl,
				const char *new_nick)
{
	handle_client_t *client = hdl->h_data;
	list_iter_t *iter = list_iter_create(client->hc_channels, FWD);
	channel_t *chan;

	if (!iter || !list_iter_access(iter)) {
		dprintf(hdl->h_fd, ":%s!%s@127.0.0.1.IP NICK %s\r\n",
			client->hc_nick, client->hc_realname, new_nick);
		return;
	}
	while ((chan = list_iter_next(iter))) {
		manager_channel_nick_notify(chan, hdl, new_nick);
	}
	free(iter);
}

void irc_cmd_nick_extract(handle_t *hdl, list_t *arg)
{
	handle_client_t *client = hdl->h_data;
	list_iter_t *iter = list_iter_create(arg, FWD);

	if (!iter)
		return;
	free(client->hc_nick);
	client->hc_nick = strdup(list_iter_access(iter));
	free(iter);
	if (client->hc_log_level == NONE)
		client->hc_log_level = NICK;
	else if (client->hc_log_level == USER) {
		client->hc_log_level = OK;
		irc_msg_welcome(hdl);
	}
}

void irc_cmd_nick(manager_t *manager, handle_t *hdl, list_t *arg)
{
	(void) manager;
	if (arg->l_size < 1) {
		dprintf(hdl->h_fd, "431  :No nickname given\r\n");
	} else {
		notify_all_chans(hdl, arg->l_start->n_data);
		irc_cmd_nick_extract(hdl, arg);
	}
}
