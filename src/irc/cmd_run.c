/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** cmd_run
*/

#include <string.h>
#include <stdlib.h>
#include "irc/cmd.h"
#include "stolist.h"

const irc_cmd_t cmd_map[] = {
	{"USER", irc_cmd_user},
	{NULL, NULL},
};

static int run_map_cmd(manager_t *manager, handle_t *hdl, list_t *cmd)
{
	char *name_cmd = irc_cmd_get_name(cmd);

	if (!name_cmd)
		return (0);
	irc_cmd_strip_to_args(cmd);
	for (unsigned int i = 0; cmd_map[i].ic_name; i++) {
		if (strcasecmp(name_cmd, cmd_map[i].ic_name) == 0
			&& cmd_map[i].ic_func) {
			cmd_map[i].ic_func(manager, hdl, cmd);
		}
	}
	free(name_cmd);
	return (0);
}

void irc_cmd_run(manager_t *manager, handle_t *hdl, const char *cmd)
{
	list_t *split_cmd = stolist_spe_irc(cmd, " ");

	if (!split_cmd)
		return;
	run_map_cmd(manager, hdl, split_cmd);
	list_destroy(split_cmd);
}
