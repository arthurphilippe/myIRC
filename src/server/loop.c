/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** loop
*/

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include "server/server.h"

static int prepare_for_select(server_t *serv, fd_set *fd_read)
{
	int highest_fd = 0;

	FD_ZERO(fd_read);
	for (unsigned int i = 0; i < MAX_HANDLES; i++) {
		if (serv->sv_handles[i].h_type != H_FREE) {
			FD_SET(serv->sv_handles[i].h_fd, fd_read);
			if (highest_fd < serv->sv_handles[i].h_fd)
				highest_fd = serv->sv_handles[i].h_fd;
		}
	}
	return (highest_fd);
}

static void read_on_set_fd(server_t *sv, fd_set *fd_read)
{
	for (unsigned int i = 0; i < MAX_HANDLES; i++) {
		if (FD_ISSET(sv->sv_handles[i].h_fd, fd_read))
			sv->sv_handles[i].h_read(sv, &sv->sv_handles[i]);
	}
}

static int body(server_t *serv)
{
	fd_set fd_read;
	int highest_fd = prepare_for_select(serv, &fd_read);
	struct timeval tv;

	tv.tv_sec = 1;
	tv.tv_usec = 0;
	if (select(highest_fd + 1, &fd_read, NULL, NULL, &tv) == -1) {
		perror("select");
		return (SERV_RET_ERR);
	}
	read_on_set_fd(serv, &fd_read);
	printf("waiting...\n");
	return (SERV_RET_OK);
}

void server_loop(server_t *serv)
{
	while (!body(serv));
}
