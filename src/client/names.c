/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** names
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "client/client.h"
#include "manager.h"
#include "stolist.h"

static int names_cmd(char *dest, char *src, int i)
{
	if (!strlen(src))
		return (i);
	if (src[0] != '#' && src[0] != '&') {
		return (ret_int_client(i,
			"/names:", "incorrect syntax on", src));
	}
	if (strlen(dest) > 0) {
		dest[i++] = ',';
	}
	for (int u = 0; src[u] != '\0'; u++) {
		dest[i++] = src[u];
	}
	return (i);
}

static char *client_create_names_cmd(list_iter_t *iterator)
{
	char *str = malloc(sizeof(char) * CMD_MAX_SIZE);
	char *tmp = NULL;
	int i = 0;

	if (!str)
		return (NULL);
	memset(str, '\0', CMD_MAX_SIZE);
	while ((tmp = list_iter_access(iterator))) {
		i = names_cmd(str, tmp, i);
		list_iter_next(iterator);
	}
	return (str);
}

int client_cmd_names(manager_t *manager, char *arg)
{
	list_t *list = stolist(arg, " ");
	client_t *client = manager->m_data;
	list_iter_t *iterator = list_iter_create(list, FWD);
	char *str = NULL;

	if (!list || !iterator || client->state == NOT_CONNECTED) {
		return (ret_int_client(RET_ERR,
					"Command names", "failed", ""));
	}
	if ((str = client_create_names_cmd(iterator)) == NULL)
		return (ret_int_client(RET_ERR, "Command names", "failed",
					"(malloc failed)"));
	dprintf(client->fd, "%s %s\r\n", "NAMES", str);
	free(iterator);
	free(str);
	list_destroy(list);
	return (0);
}
