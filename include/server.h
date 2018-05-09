/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** server
*/

#ifndef SERVER_H_
	#define SERVER_H_

	#include "list.h"

typedef struct	s_server {
	list_t	*sv_clients;
	list_t	*sv_channels;
}		server_t;

typedef struct	s_channel {
	char	*ch_name;
	list_t	*ch_clients;
}		channel_t;

void manager_channel_leave(channel_t *channel, handle_t *client);
int manager_channel_join(channel_t *channel, handle_t *client);
void manager_client_remove(manager_t *manager, handle_t *client);
int manager_client_add(manager_t *manager, handle_t *client);

#endif /* !SERVER_H_ */
