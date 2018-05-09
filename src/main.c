/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "manager.h"

int main()
{
	printf("salut, je ne regarde pas les arguments. J'utilise le port 4242\n");
	manager_t *manager = manager_create_port(4242);

	if (!manager)
		return (84);
	manager_loop(manager);
	manager_delete_port(manager);
}
