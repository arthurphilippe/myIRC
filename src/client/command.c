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
		if (str[i - 1] == '\n')
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
		free(dest);
		return (NULL);
	}
	memset(dest, '\0', strlen(cmd) + 1);
	strcpy(dest, tmp);
	return (dest);
}
