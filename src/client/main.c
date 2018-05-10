/*
** EPITECH PROJECT, 2018
** IRC Client
** File description:
** Main for client
*/

#include <stdio.h>
#include "manager.h"
#include "handle/server.h"
#include "client/client.h"

static void print_usage(void)
{
	dprintf(2, "%s\n", PRINT_USAGE);
}

int main(void)
{
	manager_t *manager = manager_create_connect();
	manager_loop(manager);
	print_usage();
	manager_delete(manager);
	return (0);
}
