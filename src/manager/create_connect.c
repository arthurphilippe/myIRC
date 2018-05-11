/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** create_connect
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "handle/server.h"
#include "client/client.h"

manager_t *manager_create_connect()
{
	manager_t *manager = manager_create();

	if (!manager) {
		perror("server_port_listen");
		return (NULL);
	}
	handle_stdin_create(manager);
	manager->m_mode = CLIENT;
	manager->m_data = malloc(sizeof(client_t));
	if (!manager->m_data) {
		free(manager);
		return (NULL);
	}
	memset(manager->m_data, '\0', sizeof(client_t));
	manager->m_delete = manager_delete_connect;
	return (manager);
}
