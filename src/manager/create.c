/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "manager.h"

/*
** Creates an empty server
*/
manager_t *server_create()
{
	manager_t *manager = malloc(sizeof(manager_t));

	if (!manager)
		return (NULL);
	memset(manager->m_handles, 0, MAX_HANDLES * sizeof(handle_t));
	return (manager);
}

/*
** Creates a server with an active listening port
*/
manager_t *manager_create_port(int port)
{
	manager_t *manager = server_create();

	if (!manager || handle_port_create(manager, port) != MANAGER_RET_OK) {
		perror("server_port_listen");
		return (NULL);
	}
	return (manager);
}
