/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** user
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "irc/cmd.h"
#include "irc/msg.h"
#include "handle/client.h"

static void cmd_user_get_realname(list_iter_t *iter)
{
	list_iter_next(iter);
	list_iter_next(iter);
	list_iter_next(iter);
}

void irc_cmd_user_extract(handle_t *hdl, list_t *arg)
{
	handle_client_t *client = hdl->h_data;
	list_iter_t *iter = list_iter_create(arg, FWD);

	if (!iter)
		return;
	free(client->hc_username);
	client->hc_username = strdup(list_iter_access(iter));
	if (!client->hc_nick)
		client->hc_nick = strdup(list_iter_access(iter));
	cmd_user_get_realname(iter);
	free(client->hc_realname);
	client->hc_realname = strdup(list_iter_access(iter));
	free(iter);
	if (client->hc_log_level == NONE)
		client->hc_log_level = USER;
	else {
		client->hc_log_level = OK;
		irc_msg_welcome(hdl);
	}
}

void irc_cmd_user(manager_t *manager, handle_t *hdl, list_t *arg)
{
	handle_client_t *client = hdl->h_data;

	(void) manager;
	if (arg->l_size < 4) {
		dprintf(hdl->h_fd, "461  USER :Not enough parameters\r\n");
	} else if (client->hc_log_level == OK) {
		dprintf(hdl->h_fd, "462 %s :You may not reregister\r\n",
			client->hc_nick);
	} else {
		irc_cmd_user_extract(hdl, arg);
	}
}
