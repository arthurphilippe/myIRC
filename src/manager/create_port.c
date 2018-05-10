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
	server_t *serv;

	if (!manager || handle_port_create(manager, port) != MANAGER_RET_OK) {
		perror("server_port_listen");
		return (NULL);
	}
	manager->m_data = malloc(sizeof(server_t));
	if (!manager->m_data) {
		free(manager);
		return (NULL);
	}
	serv = manager->m_data;
	serv->sv_channels = list_create(manager_channel_destroy);
	serv->sv_clients = list_create(NULL);
	manager->m_mode = SERVER;
	manager->m_delete = manager_delete_port;
	return (manager);
}
