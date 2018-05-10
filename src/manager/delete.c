/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** delete
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include "manager.h"

void manager_delete(manager_t *manager)
{
	for (unsigned int i = 0; i < MAX_HANDLES; i++) {
		if (manager->m_handles[i].h_type == H_PORT) {
			shutdown(manager->m_handles[i].h_fd, SHUT_RDWR);
			close(manager->m_handles[i].h_fd);
		}
	}
	if (manager->m_delete)
		manager->m_delete(manager);
	free(manager);
}
