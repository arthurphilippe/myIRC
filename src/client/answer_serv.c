/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** answer_serv
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client/client.h"

const cmd_t cmd_answer_map[] = {
	{SERV_CMD_PONG, UNK_STATE, client_cmd_pong},
	{"", UNK_STATE, NULL},
};

int client_cmd_answer(manager_t *manager, const char *cmd)
{
	char *cmd_name = client_cmd_extract_name(cmd, " ");
	char *cmd_arg = NULL;
	bool launch = false;

	for (int i = 0; cmd_answer_map[i].ptr != NULL && launch == false; i++) {
		if (!strcmp(cmd_answer_map[i].cmd_name, cmd_name)) {
			cmd_arg = client_cmd_extract_arg(cmd, " ");
			if (!cmd_arg)
				break;
			if (!cmd_answer_map[i].ptr(manager, cmd_arg))
				launch = true;
			free(cmd_arg);
			break;
		}
	}
	free(cmd_name);
	return (0);
}
