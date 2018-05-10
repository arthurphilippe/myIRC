/*
** EPITECH PROJECT, 2018
** IRC Client
** File description:
** Main for client
*/

#include <stdio.h>
#include "client/client.h"
#include "manager.h"

static void print_usage(void)
{
	dprintf(2, "%s\n", PRINT_USAGE);
}

int main(void)
{
	manager_t *manager = manager_create_connect();
	manager_loop(manager);
	print_usage();
	return (0);
}