/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** create_connect
*/

#include <stdio.h>
#include "handle/server.h"

manager_t *manager_create_connect()
{
	manager_t *manager = manager_create();

	if (!manager) {
		perror("server_port_listen");
		return (NULL);
	}
	handle_stdin_create(manager);
	manager->m_data = NULL;
	manager->m_mode = CLIENT;
	manager->m_delete = manager_delete_connect;
	return (manager);
}
