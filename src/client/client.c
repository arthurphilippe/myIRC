/*
** EPITECH PROJECT, 2018
** Client IRC
** File description:
** IRC Core Func
*/

#include <stdlib.h>
#include <stdio.h>
#include <client/client.h>

static int client_process()
{
	int loop = 1;
	char *str = NULL;
	size_t len = 0;
	char *cmd;


	while (loop) {
		len = 0;
		getline(&str, &len, stdin);
		if (str && len > 1) {
			str[len - 1] = '\0';
			remove_carriage_ret(str);
			if (client_check_connect_serv(str))
				exit(22);
			printf("%s\n", str);
			free(str);
		}
	}
	return (0);
}

int client_irc()
{
	client_process();
	return (0);
}
