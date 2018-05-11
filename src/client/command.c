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
#include "client/cmd.h"

void remove_carriage_ret(char *str)
{
	int i = strlen(str);

	if (i > 0) {
		if ((str[i - 1] == '\n'))
			str[i - 1] = '\0';
	}
}

char *client_cmd_extract_name(const char *str, const char *delim)
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

char *client_cmd_extract_arg(const char *cmd, char *delim)
{
	char *tmp = NULL;
	char *dest = malloc(sizeof(char) * CMD_MAX_SIZE);
	char s[1024];
	int u = 0;
	int len;

	memset(s, '\0', 1024);
	strcpy(s, cmd);
	if (!dest)
		return (NULL);
	tmp = strtok (s, delim);
	if (tmp == NULL || (len = strlen(tmp)) <= 0) {
		free(dest);
		return (NULL);
	}
	memset(dest, '\0', CMD_MAX_SIZE);
	for (int i = len + 1; cmd[i] != '\0'; i++) {
		dest[u++] = cmd[i];
	}
	return (dest);
}
