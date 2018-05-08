/*
** EPITECH PROJECT, 2018
** Client IRC
** File description:
** IRC Core Func
*/

#include <stdlib.h>
#include <stdio.h>
#include <client/client.h>

static client_t *client_set_connection(char *cmd)
{
	client_t *client = NULL;

	if ((client = client_check_connect_serv(cmd))
			&& client->state == CONNECTED) {
		printf("%s\n", client->serv_ip);
		return (client);
	} else {
		if (client != NULL)
			free(client);
		dprintf(2, "%s\n", CLIENT_NOT_CONNECTED);
	}
	return (client);
}

static void initialize(char **str, size_t *len, client_t **setco)
{
	*len = 0;
	*str = NULL;
	*setco = NULL;
}

static int client_basic_info_loop(void)
{
	char *str = NULL;
	size_t len = 0;
	client_t *setco = NULL;

	while (true) {
		initialize(&str, &len, &setco);
		if ((getline(&str, &len, stdin)) == -1) {
			free(str);
			if (setco != NULL) {
				free(setco->serv_ip);
				free(setco);
			}
			break;
		}
		remove_carriage_ret(str);
		setco = client_set_connection(str);
		if (setco != NULL)
			free(setco);
		free(str);
	}
	return (0);
}

int client_irc()
{
	client_basic_info_loop();
	return (0);
}
