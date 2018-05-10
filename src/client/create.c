/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** create c
*/

#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "client/client.h"
#include "handle/server.h"

static int manager_set_fd(manager_t *manager)
{
	handle_stdin_create(manager);
	return (MANAGER_RET_OK);
}

manager_t *manager_create_connect()
{
	manager_t *manager = manager_create();

	if (!manager || manager_set_fd(manager) != MANAGER_RET_OK) {
		perror("server_port_listen");
		return (NULL);
	}
	manager->m_data = NULL;
	manager->m_mode = CLIENT;
	return (manager);
}
