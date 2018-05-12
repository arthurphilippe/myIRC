/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** part
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "client/client.h"
#include "manager.h"
#include "stolist.h"

/*
**	format the string to a RFC compliant string
**	taking the destination string, the source
**	where to start in the destination
*/
static int part_cmd(char *dest, char *src, int i)
{
	if (src[0] != '#' && src[0] != '&') {
		return (ret_int_client(i,
			"/part:", "incorrect syntax on", src));
	}
	if (strlen(dest) > 0) {
		dest[i++] = ',';
	}
	for (int u = 0; src[u] != '\0'; u++) {
		dest[i++] = src[u];
	}
	return (i);
}

/*
**	Read all of the strings in the list
**	concat all the strings in one char* returned.
*/
static char *client_create_part_cmd(list_iter_t *iterator)
{
	char *str = malloc(sizeof(char) * CMD_MAX_SIZE);
	char *tmp = NULL;
	int i = 0;

	if (!str)
		return (NULL);
	memset(str, '\0', CMD_MAX_SIZE);
	while(1) {
		tmp = list_iter_access(iterator);
		if (!tmp)
			break;
		i = part_cmd(str, tmp, i);
		list_iter_next(iterator);
	}
	return (str);
}

int client_cmd_part(manager_t *manager, char *arg)
{
	list_t *list = stolist(arg, " ");
	client_t *client = manager->m_data;
	list_iter_t *iterator = list_iter_create(list, FWD);
	char *str = NULL;

	if (!list || !iterator || client->state == NOT_CONNECTED) {
		return (ret_int_client(RET_ERR, "Command part", "failed", ""));
	}
	if ((str = client_create_part_cmd(iterator)) == NULL)
		return (ret_int_client(RET_ERR, "Command part", "failed",
							"(malloc failed)"));
	if (strlen(str) > 0)
		dprintf(client->fd, "%s %s\r\n", "PART", str);
	free(iterator);
	free(str);
	list_destroy(list);
	return (0);
}
