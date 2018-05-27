/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** privmsg
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "client/client.h"
#include "manager.h"
#include "stolist.h"

static int msg_cmd(char *dest, char *src, int i)
{
	if (strlen(dest) > 0) {
		dest[i++] = ' ';
	}
	for (int u = 0; src[u] != '\0'; u++) {
		dest[i++] = src[u];
	}
	return (i);
}

/*
** Read all of the strings in the list
** concat all the strings in one char * returned.
*/
static char *client_create_msg_cmd(list_iter_t *iterator)
{
	char *str = malloc(sizeof(char) * CMD_MAX_SIZE);
	char *tmp = NULL;
	int i = 0;

	if (!str)
		return (NULL);
	memset(str, '\0', CMD_MAX_SIZE);
	while ((tmp = list_iter_access(iterator))) {
		i = msg_cmd(str, tmp, i);
		list_iter_next(iterator);
	}
	return (str);
}

int client_cmd_msg(manager_t *manager, char *arg)
{
	list_t *list = stolist(arg, " ");
	list_iter_t *iterator = list_iter_create(list, FWD);
	char *who = NULL;
	char *msg;
	client_t *client = manager->m_data;

	if (list->l_size < 2 || !client || client->state != CONNECTED) {
		list_destroy(list);
		free(iterator);
		return (ret_int_client(0, "/msg: ", "USAGE /msg $user $text",
					""));
	}
	who = list_iter_access(iterator);
	if (who[0] == '#') {
	} else if ((msg = client_create_msg_cmd(iterator))) {
		dprintf(client->fd, "PRIVMSG %s :%s\n", who, msg);
		free(msg);
	}
	free(iterator);
	list_destroy(list);
	return (0);
}
