/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** port_listen
*/

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "server/server.h"

static int port_bind(int sock, int port)
{
	struct sockaddr_in sin;

	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = INADDR_ANY;
	return (bind(sock, (struct sockaddr *) &sin, sizeof(sin)));
}

int server_port_listen(server_t *serv, int port)
{
	handle_t *hdl = server_handle_get_free(serv);
	int sock = socket(PF_INET, SOCK_STREAM, 0);

	if (!hdl || sock == -1
		|| port_bind(sock, port) == -1
		|| listen(sock, SERV_BACKLOG) == -1) {
		close(sock);
		return (SERV_RET_ERR);
	}
	hdl->h_type = H_PORT;
	hdl->h_fd = sock;
	hdl->h_read = server_port_read;
	hdl->h_write = NULL;
	return (SERV_RET_OK);
}
