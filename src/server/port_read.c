/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** read
*/

#include <sys/socket.h>
#include <arpa/inet.h>
#include "server/server.h"

/*
** To be called when fd is active
*/
void server_port_read(server_t *serv, handle_t *port_hdl)
{
	int socket;
	struct sockaddr_in sin;
	socklen_t sin_len = sizeof(sin);
	handle_t *client_hdl = server_handle_get_free(serv);

	if (!client_hdl)
		return;
	socket = accept(port_hdl->h_fd, (struct sockaddr *) &sin, &sin_len);
	if (socket == -1)
		return;
	client_hdl->h_fd = socket;
	client_hdl->h_type = H_CLIENT;
	client_hdl->h_read = server_client_read;
	// client_hdl->h_write =
}
