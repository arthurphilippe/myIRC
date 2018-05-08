/*
** EPITECH PROJECT, 2018
** Client FTP
** File description:
** set structure
*/

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include "client/client.h"

static int	set_fd(client_t *client)
{
	struct sockaddr_in addr;
	struct protoent	*pt = getprotobyname("TCP");
	struct hostent *ip = NULL;
	struct in_addr **serv_char_ip = NULL;

	memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(client->port);
	if ((ip = gethostbyname(client->serv_ip)) == NULL) {
		perror("gethostbyname");
		return (RET_ERR);
	}
	serv_char_ip = (struct in_addr **) ip->h_addr_list;
	inet_pton(AF_INET, inet_ntoa(*serv_char_ip[0]), &addr.sin_addr);
	client->fd = socket(AF_INET, SOCK_STREAM, pt->p_proto);
	if (connect(client->fd, (const struct sockaddr *)&addr,
						sizeof(addr)) == -1)
		return (ret_int_error(RET_ERR, "connect failed: ",
				"can't connect to", " the specified server"));
	client->state = CONNECTED;
	return (0);
}

client_t	*client_set_server_info(char *arg)
{
	client_t *new_client = malloc(sizeof(client_t));
	char *tmp;

	if (!new_client)
		return (ret_null_error("malloc: ", MALLOC_FAIL, NULL));
	memset(new_client, '\0', sizeof(client_t));
	tmp = extract_cmd_arg(arg, ":");
	if (tmp == NULL)
		new_client->port = 6667;
	else {
		new_client->port = atoi(tmp);
		free(tmp);
	}
	if (new_client->port == 0) {
		ret_null_error("atoi failed: ", ARG2_FAIL,
					", using default port '6667'");
		new_client->port = 6667;
	}
	new_client->serv_ip = extract_command(arg, ":");
		if (set_fd(new_client) == RET_ERR) {
			free(new_client->serv_ip);
			free(new_client);
			return (NULL);
		}
	return (new_client);
}
