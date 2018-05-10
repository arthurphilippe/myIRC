/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** server
*/

#ifndef SERVER_H_
	#define SERVER_H_

	#include "manager.h"

int handle_server_create(manager_t *manager, int fd);
int handle_stdin_create(manager_t *manager);
void handle_stdin_read(manager_t *manager, handle_t *hdl);
void client_read_serv(manager_t *manager, handle_t *client_hdl);

#endif /* !SERVER_H_ */
