/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** client_cmd_run
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client/client.h"
#include "client/cmd.h"

const cmd_t cmd_map[] = {
	{CLIENT_CMD_SERVER, NOT_CONNECTED, manager_connect_to_server},
	{CLIENT_CMD_NICK, NOT_CONNECTED, client_cmd_nick},
	{CLIENT_CMD_QUIT, NOT_CONNECTED, client_cmd_quit},
	{CLIENT_CMD_EXIT, NOT_CONNECTED, client_cmd_quit},
	{CLIENT_CMD_JOIN, CONNECTED, client_cmd_join},
	{CLIENT_CMD_PART, CONNECTED, client_cmd_part},
	{CLIENT_CMD_LIST, CONNECTED, client_cmd_list},
	{CLIENT_CMD_USERS, CONNECTED, client_cmd_users},
	{CLIENT_CMD_NAMES, CONNECTED, client_cmd_names},
	{"", UNK_STATE, NULL}
};

static void clean(char *cmd_arg, char *cmd_name)
{
	if (cmd_arg)
		free(cmd_arg);
	free(cmd_name);
}

int client_cmd_run(manager_t *manager, const char *cmd)
{
	char *cmd_name = client_cmd_extract_name(cmd, CMD_MAIN_DELIM);
	char *cmd_arg = NULL;
	client_t *client = manager->m_data;
	bool launch = false;

	for (int i = 0; cmd_name != NULL && cmd_map[i].ptr != NULL
					&& launch == false ; i++) {
		if (!strcmp(cmd_map[i].cmd_name, cmd_name)) {
			cmd_arg = client_cmd_extract_arg(cmd, CMD_MAIN_DELIM);
			if (!cmd_map[i].ptr(manager, cmd_arg))
				launch = true;
		}
	}
	if (launch == false && client->fd == 0) {
		ret_int_client(0, "Client", "not connected", "to server");
	} else if (client->fd != 0 && launch == false) {
		client_cmd_privmsg(manager, strdup(cmd));
	}
	clean(cmd_arg, cmd_name);
	return (0);
}
