/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include "manager.h"
#include "server.h"

manager_t *g_manager;

static void upon_signal(int signum)
{
	(void) signum;
	manager_delete(g_manager);
	exit(0);
}

/*
** Creates an empty server
*/
manager_t *manager_create(void)
{
	manager_t *manager = malloc(sizeof(manager_t));

	if (!manager)
		return (NULL);
	memset(manager->m_handles, 0, MAX_HANDLES * sizeof(handle_t));
	manager->m_data = NULL;
	manager->m_live = true;
	g_manager = manager;
	signal(SIGINT, upon_signal);
	return (manager);
}
