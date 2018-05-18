/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

int main(int ac, char **av)
{
	manager_t *manager = NULL;

	if (ac >= 2)
		manager = manager_create_port(atoi(av[1]));
	if (!manager)
		return (84);
	manager_loop(manager);
	manager_delete(manager);
	return (0);
}
