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

// static client_t *client_set_structure(char *arg)
// {
// 	client_t *new_client = malloc(sizeof(client_t));

// 	if (!new_client)
// 		return (NULL);
// 	new_client->state = NOT_CONNECTED;
// 	new_client->port = 6667;
// 	memset(new_client->serv_ip, '\0', 1024);
// 	return (new_client);
// }

client_t *client_check_connect_serv(char *user_cmd)
{
	client_t *client = NULL;
	char *client_cmd = NULL;

	client_cmd = extract_command(user_cmd, " ");
	if (client_cmd == NULL || (strlen(client_cmd) < 6)) {
		if (client_cmd != NULL)
			free(client_cmd);
		return (NULL);
	}
	if (!strcmp(client_cmd, "/server")) {
		free(client_cmd);
		client_cmd = extract_cmd_arg(user_cmd, " ");
		client = client_set_server_info(client_cmd);
		if (client_cmd != NULL)
			free(client_cmd);
	}
	return (client);
}

char *extract_command(char *str, const char *delim)
{
	char *tmp;
	char *dest = malloc(sizeof(char) * (strlen(str) + 1));
	char s[1024];

	if (dest == NULL)
		return (NULL);
	memset(s, '\0', 1024);
	memset(dest, '\0', strlen(str) + 1);
	strcpy(s, str);
	tmp = strtok(s, delim);
	if (tmp == NULL) {
		free(dest);
		return (NULL);
	}
	strcpy(dest, tmp);
	return (dest);
}

char 	*extract_cmd_arg(char *cmd, const char *delim)
{
	char *tmp;
	char *dest = malloc(sizeof(char) * (strlen(cmd) + 1));
	char s[1024];

	if (dest == NULL)
		return (NULL);
	memset(s, '\0', 1024);
	strcpy(s, cmd);
	tmp = strtok (s, delim);
	for (int i = 0; i < 1 && tmp != NULL; i++) {
		tmp = strtok(NULL, delim);
	}
	if (tmp == NULL) {
		return (cmd);
	}
	memset(dest, '\0', strlen(cmd) + 1);
	strcpy(dest, tmp);
	return (dest);
}
