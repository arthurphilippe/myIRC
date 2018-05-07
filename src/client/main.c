/*
** EPITECH PROJECT, 2018
** IRC Client
** File description:
** Main for client
*/

#include <stdio.h>
#include "client/client.h"

static void print_usage(void)
{
	dprintf(2, "%s\n", PRINT_USAGE);
}

int main(void)
{
	print_usage();
	client_irc();
	return (0);
}
