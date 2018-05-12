/*
** EPITECH PROJECT, 2018
** Client FTP
** File description:
** Errors Functions
*/

#include <stdio.h>
#include "client/client.h"

int ret_int_error(int ret, const char *msg, const char *what, const char *end)
{
	if (!end && !msg)
		dprintf(2, "::\033[1;31merror:\033[0m \033[1m%s\033[m\n",
								msg);
	else if (!msg)
		dprintf(2, "::\033[1;31merror:\033[0m \033[1m%s\033[m%s\n",
								what, end);
	else if (!end)
		dprintf(2, "::\033[1;31merror:\033[0m %s\033[1m%s\033[m\n",
								msg, what);
	else
		dprintf(2, "::\033[1;31merror:\033[0m %s\033[1m%s\033[m%s\n",
							msg, what, end);
	return (ret);
}

void *ret_null_error(const char *msg, const char *what, const char *end)
{
	if (!end && !msg)
		dprintf(2, "::\033[1;31merror:\033[0m \033[1m%s\033[m\n",
								what);
	else if (!msg)
		dprintf(2, "::\033[1;31merror:\033[0m \033[1m%s\033[m%s\n",
								what, end);
	else if (!end)
		dprintf(2, "::\033[1;31merror:\033[0m %s\033[1m%s\033[m\n",
								msg, what);
	else
		dprintf(2, "::\033[1;31merror:\033[0m %s\033[1m%s\033[m%s\n",
							msg, what, end);
	return (NULL);
}

int ret_int_client(int ret, const char *msg, const char *what, const char *end)
{
	if (!end && !msg)
		dprintf(2, ANSI_COLOR_MAGENTA
		"Client::"ANSI_COLOR_RESET
		"\033[1;31merror:\033[0m \033[1m%s\033[m\n", msg);
	else if (!msg)
		dprintf(2, ANSI_COLOR_MAGENTA
		"Client::"ANSI_COLOR_RESET
		"\033[1;31merror:\033[0m \033[1m %s\033[m %s\n", what, end);
	else if (!end)
		dprintf(2, ANSI_COLOR_MAGENTA
		"Client::"ANSI_COLOR_RESET
		"\033[1;31merror:\033[0m %s\033[1m %s\033[m\n", msg, what);
	else
		dprintf(2, ANSI_COLOR_MAGENTA
		"Client::"ANSI_COLOR_RESET
		"\033[1;31merror:\033[0m %s\033[1m %s\033[m %s\n", msg,
				what, end);
	return (ret);
}
