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
		irc_cmd_nick_extract(hdl, arg);
	}
}
