/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** create_port
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include "manager.h"
#include "server.h"

/*
** Creates a server with an active listening port
*/
manager_t *manager_create_port(int port)
{
	manager_t *manager = manager_create();

	if (!manager || handle_port_create(manager, port) != MANAGER_RET_OK) {
		perror("server_port_listen");
		return (NULL);
	}
	manager->m_data = malloc(sizeof(server_t));
	if (!manager->m_data) {
		free(manager);
		return (NULL);
	}
	manager->m_mode = SERVER;
	return (manager);
}
