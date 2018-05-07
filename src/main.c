/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** main
*/

#include <stdio.h>
#include "server/server.h"

int main()
{
	printf("salut\n");
	server_t *serv = server_create_port(4242);

	if (!serv)
		return (84);
	server_loop(serv);
}
