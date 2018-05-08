/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** handle_get
*/

#include "manager.h"

handle_t *manager_handle_get_free(manager_t *serv)
{
	for (unsigned int i = 0; i < MAX_HANDLES; i++) {
		if (serv->m_handles[i].h_type == H_FREE)
			return (&serv->m_handles[i]);
	}
	return (NULL);
}

handle_t *manager_handle_get_from_fd(manager_t *serv, int fd)
{
	for (unsigned int i = 0; i < MAX_HANDLES; i++) {
		if (serv->m_handles->h_type != H_FREE
			&& serv->m_handles->h_fd == fd)
			return (&serv->m_handles[i]);
	}
	return (NULL);
}
