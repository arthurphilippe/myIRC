/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** handle_get
*/

#include "server/server.h"

handle_t *server_handle_get_free(server_t *serv)
{
	for (unsigned int i = 0; i < MAX_HANDLES; i++) {
		if (serv->sv_handles[i].h_type == H_FREE)
			return (&serv->sv_handles[i]);
	}
	return (NULL);
}

handle_t *server_handle_get_from_fd(server_t *serv, int fd)
{
	for (unsigned int i = 0; i < MAX_HANDLES; i++) {
		if (serv->sv_handles->h_type != H_FREE
			&& serv->sv_handles->h_fd == fd)
			return (&serv->sv_handles[i]);
	}
	return (NULL);
}
