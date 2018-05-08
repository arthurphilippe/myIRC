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

	if ((client = client_check_connect_serv(cmd))) {
		printf("%s\n", client->serv_ip);
		printf("%d\n", client->port);
	} else
		dprintf(2, "%s\n", CLIENT_NOT_CONNECTED);
	return (client);
}

static int client_process(void)
{
	char *str = NULL;
	size_t len = 0;
	client_t *setco = NULL;

	while (true) {
		len = 0;
		str = NULL;
		if ((getline(&str, &len, stdin)) == -1) {
			free(str);
			if (setco) {
				free(setco->serv_ip);
				free(setco);
			}
			break;
		}
		remove_carriage_ret(str);
		setco = client_set_connection(str);
		free(str);
	}
	return (0);
}

int client_irc()
{
	client_process();
	return (0);
}
