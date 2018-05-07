/*
** EPITECH PROJECT, 2018
** IRC client
** File description:
** command functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client/client.h"

void remove_carriage_ret(char *str)
{
	int i = strlen(str);

	if (i > 0) {
		if ((str[i - 1] == '\n'))
			str[i - 1] = '\0';
	}
}

static client_t *client_set_structure(char *arg)
{
	client_t *new_client = malloc(sizeof(client_t));

	if (!new_client)
		return (NULL);
	new_client->state = NOT_CONNECTED;
	new_client->port = 6667;
	memset(new_client->serv_ip, '\0', 1024);
	return (new_client);
}

client_t *client_check_connect_serv(char *user_cmd)
{
	client_t *client;
	char *client_cmd;

	client_cmd = extract_command(user_cmd);
	if (!client_cmd || (strlen(client_cmd) < 7))
		return (false);
	if (!strcmp(client_cmd, "/server")) {
		free(client_cmd);
		client_cmd = extract_cmd_arg(user_cmd);
		printf("%s\n", client_cmd);
		client = client_set_structure(client_cmd);
		free(client_cmd);
	}
	return (client);
}

char *extract_command(char *str)
{
	char *tmp;
	char *dest = malloc(sizeof(char) * strlen(str));

	if (!dest)
		return (NULL);
	memset(dest, '\0', strlen(str));
	strcpy(dest, str);
	tmp = strtok(str, " ");
	if (tmp == NULL) {
		return (0);
	}
	memset(dest, '\0', strlen(str));
	strcpy(dest, tmp);
	return (dest);
}

char 	*extract_cmd_arg(const char *cmd)
{
	char *tmp;
	char *dest = malloc(sizeof(char) * strlen(cmd));

	if (!dest)
		return (NULL);
	memset(dest, '\0', strlen(cmd));
	strcpy(dest, cmd);
	tmp = strtok (dest, " ");
	for (int i = 0; i < 1 && tmp != NULL; i++) {
		tmp = strtok(NULL, " ");
	}
	if (tmp == NULL) {
		return (NULL);
	}
	strcpy(dest, tmp);
	return (dest);
}
