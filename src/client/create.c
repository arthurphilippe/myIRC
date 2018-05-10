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

static int	manager_set_ip(client_t *client, struct sockaddr_in *addr)
{
	struct hostent *ip = NULL;
	memset(*&addr, 0, sizeof(struct sockaddr_in));
	addr->sin_family = AF_INET;
	addr->sin_port = htons(client->port);
	struct in_addr **serv_char_ip = NULL;

	if ((ip = gethostbyname(client->serv_ip)) != NULL) {
		serv_char_ip = (struct in_addr **) ip->h_addr_list;
		inet_pton(AF_INET,
				inet_ntoa(*serv_char_ip[0]), &addr->sin_addr);
	} else {
		inet_pton(AF_INET,
				client->serv_ip, &addr->sin_addr);
	}
	return (0);
}

static int	manager_set_client_fd(client_t *client)
{
	struct protoent	*pt = getprotobyname("TCP");
	struct sockaddr_in addr;

	manager_set_ip(client, &addr);
	client->fd = socket(AF_INET, SOCK_STREAM, pt->p_proto);
	if (connect(client->fd, (const struct sockaddr *)&addr,
						sizeof(addr)) == -1)
		return (ret_int_error(RET_ERR, "connect failed: ",
				"can't connect to", " the specified server"));
	dprintf(client->fd, "coucou\r\n");
	client->state = CONNECTED;
	return (0);
}

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
	client_t *client = manager->m_data;

	manager_set_client_fd(client);
	hdl->h_type = H_CLIENT;
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
