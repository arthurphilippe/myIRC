/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** quit
*/

#include "manager.h"

int client_cmd_quit(manager_t *manager, char *arg)
{
	(void) arg;
	manager->m_live = false;
	return (0);
}
