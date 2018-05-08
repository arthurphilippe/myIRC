/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** main
*/

#include <stdio.h>
#include "manager.h"

int main()
{
	printf("salut\n");
	manager_t *serv = manager_create_port(4242);

	if (!serv)
		return (84);
	manager_loop(serv);
}
