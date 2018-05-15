/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** names
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "irc/cmd.h"
#include "irc/msg.h"
#include "server.h"
#include "handle/client.h"

static void list_all(manager_t *manager, handle_t *hdl)
{
	server_t *serv = manager->m_data;
	list_iter_t *iter = list_iter_create(serv->sv_channels, FWD);
	channel_t *chan;

	while ((chan = list_iter_access(iter))) {
		manager_channel_names(chan, hdl);
		list_iter_next(iter);
	}
	free(iter);
}

static void list_from_args(manager_t *manager, handle_t *hdl, list_t *arg)
{
	list_iter_t *iter = list_iter_create(arg, FWD);
	char *tmp;

	while ((tmp = list_iter_access(iter))) {
		manager_channel_names_by_name(manager, hdl, tmp);
		list_iter_next(iter);
	}
	free(iter);
}

void irc_cmd_names(manager_t *manager, handle_t *hdl, list_t *arg)
{
	if (!arg->l_size)
		list_all(manager, hdl);
	else
		list_from_args(manager, hdl, arg);
}
