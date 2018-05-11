/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** cmd_strip_to_args
*/

#include <stdlib.h>
#include "irc/cmd.h"
#include "stolist.h"

void irc_cmd_strip_to_args(list_t *cmd)
{
	list_iter_t *iter = list_iter_create(cmd, FWD);
	char *tmp;

	if (iter && (tmp = list_iter_access(iter))) {
		if (tmp[0] == ':')
			list_erase(iter);
		list_erase(iter);
	}
	free(iter);
}
