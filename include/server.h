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

int manager_channel_create(manager_t *manager, const char *name);
void manager_channel_leave(channel_t *channel, handle_t *client);
void manager_channel_leave_by_name(manager_t *manager, handle_t *client,
					const char *chan_name);
int manager_channel_join(channel_t *channel, handle_t *client);
int manager_channel_join_by_name(manager_t *manager,
					const char *chanstr,
					handle_t *client);
void manager_channel_destroy(void *ptr);
channel_t *manager_channel_find(manager_t *manager, const char *str);

void manager_client_remove(manager_t *manager, handle_t *client);
int manager_client_add(manager_t *manager, handle_t *client);
int handle_client_set_nick(handle_t *client_hdl, const char *nick);

#endif /* !SERVER_H_ */
