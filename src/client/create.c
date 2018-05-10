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

static int manager_set_entry(manager_t *manager)
{
	handle_t *hdl = manager_handle_get_free(manager);

	hdl->h_fd = STDIN_FILENO;
	hdl->h_type = H_STDIN;
	hdl->h_read = client_irc;
	hdl->h_write = NULL;
	return (MANAGER_RET_OK);
}

int manager_set_irc_socket(manager_t *manager, int fd)
{
	handle_t *hdl = manager_handle_get_free(manager);

	hdl->h_type = H_SERVER;
	hdl->h_fd = fd;
	hdl->h_read = client_read_serv;
	hdl->h_write = NULL;
	return (MANAGER_RET_OK);
}

static int manager_set_fd(manager_t *manager)
{
	manager_set_entry(manager);
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
