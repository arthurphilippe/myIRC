/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** cmd_get_name
*/

#include <stdlib.h>
#include <string.h>
#include "irc/cmd.h"
#include "stolist.h"

char *irc_cmd_get_name(list_t *split_cmd)
{
	list_iter_t *iter = list_iter_create(split_cmd, FWD);
	char *tmp = NULL;

	if (iter && (tmp = list_iter_next(iter))) {
		if (tmp[0] != ':') {
			free(iter);
			return (strdup(tmp));
		}
		tmp = list_iter_access(iter);
		free(iter);
		return (strdup(tmp));
	}
	free(iter);
	return (NULL);
}
