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

int main(void)
{
	manager_t *manager = manager_create_connect();

	if (!manager)
		return (84);
	manager_loop(manager);
	manager_delete(manager);
	return (0);
}
