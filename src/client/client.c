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

	while (loop) {
		len = 0;
		str = NULL;
		if ((getline(&str, &len, stdin)) == -1) {
			free(str);
			return (0);
		}
		remove_carriage_ret(str);
		if (client_check_connect_serv(str))
			return (ret_int_error(RET_ERR, "OK", "OK", "OK"));
		else
			dprintf(2, "%s\n", CLIENT_NOT_CONNECTED);
		printf("%s\n", str);
		free(str);
	}
	return (0);
}

int client_irc()
{
	client_process();
	return (0);
}
