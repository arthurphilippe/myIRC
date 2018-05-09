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
#include "manager.h"

static int prepare_for_select(manager_t *manager, fd_set *fd_read)
{
	int highest_fd = 0;

	FD_ZERO(fd_read);
	for (unsigned int i = 0; i < MAX_HANDLES; i++) {
		if (manager->m_handles[i].h_type != H_FREE) {
			FD_SET(manager->m_handles[i].h_fd, fd_read);
			if (highest_fd < manager->m_handles[i].h_fd)
				highest_fd = manager->m_handles[i].h_fd;
		}
	}
	return (highest_fd);
}

static void read_on_set_fd(manager_t *sv, fd_set *fd_read)
{
	for (unsigned int i = 0; i < MAX_HANDLES; i++) {
		if (FD_ISSET(sv->m_handles[i].h_fd, fd_read))
			sv->m_handles[i].h_read(sv, &sv->m_handles[i]);
	}
}

static int body(manager_t *manager)
{
	fd_set fd_read;
	int highest_fd = prepare_for_select(manager, &fd_read);
	struct timeval tv;

	tv.tv_sec = 1;
	tv.tv_usec = 0;
	if (select(highest_fd + 1, &fd_read, NULL, NULL, &tv) == -1) {
		perror("select");
		return (MANAGER_RET_ERR);
	}
	read_on_set_fd(manager, &fd_read);
	return (MANAGER_RET_OK);
}

void manager_loop(manager_t *manager)
{
	while (!body(manager) && manager->m_live == true);
}
