/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** join
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "irc/cmd.h"
#include "irc/msg.h"
#include "handle/client.h"
#include "server.h"
#include "stolist.h"

static list_t *get_channel_list(const char *arg)
{
	list_t *list = stolist(arg, " ");

	if (!list)
		return (NULL);
	return (list);
}

static void irc_cmd_join_channel(manager_t *manager, handle_t *hdl, char *arg)
{
	list_t *list = get_channel_list(arg);
	list_iter_t *it = list_iter_create(list, FWD);
	char *tmp;

	if (!list || !it) {
		list_destroy(list);
		free(it);
		return;
	}
	while ((tmp = list_iter_access(it))) {
		manager_channel_join_by_name(manager, tmp, hdl);
		manager_channel_names_by_name(manager, hdl, tmp);
		list_iter_next(it);
	}
	free(it);
	list_destroy(list);
}

static void irc_cmd_join_extract(manager_t *manager,
				handle_t *hdl, list_t *arg)
{
	list_iter_t *iter = list_iter_create(arg, FWD);
	char *tmp = NULL;

	if (!iter)
		return;
	tmp = list_iter_access(iter);
	irc_cmd_join_channel(manager, hdl, tmp);
	free(iter);
}

void irc_cmd_join(manager_t *manager, handle_t *hdl, list_t *arg)
{
	handle_client_t *client = hdl->h_data;

	if (arg->l_size < 1) {
		dprintf(hdl->h_fd, "461 %s JOIN :Not enough parameters\r\n",
			client->hc_nick);
	} else {
		irc_cmd_join_extract(manager, hdl, arg);
	}
}
