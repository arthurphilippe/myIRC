/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** privmsg
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "irc/cmd.h"
#include "irc/msg.h"
#include "handle/client.h"
#include "server.h"
#include "stolist.h"

static void send_msg(manager_t *manager, handle_t *hdl,
			const char *dest, const char *msg)
{
	void *recp = manager_channel_find(manager, dest);

	if (recp) {
		manager_channel_send_msg(recp, msg, dest);
	} else {
		recp = handle_client_find(manager, dest);
		irc_msg_client(hdl, msg, dest);
	}
}

void irc_cmd_privmsg(manager_t *manager, handle_t *hdl, list_t *arg)
{
	handle_client_t *data = hdl->h_data;

	if (arg->l_size < 1) {
		dprintf(hdl->h_fd, ":myirc_serv 411 %s :no recipient\r\n",
			data->hc_nick);
	} else if (arg->l_size < 2) {
		dprintf(hdl->h_fd, ":myirc_serv 412 %s :no text\r\n",
			data->hc_nick);
	} else
		send_msg(manager, hdl, arg->l_start->n_data,
				arg->l_end->n_data);
}
