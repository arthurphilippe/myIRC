/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** server
*/

#ifndef SERVER_H_
	#define SERVER_H_

	#include "list.h"

typedef struct	s_server {
	list_t	*clients;
	list_t	*channels;
}		server_t;

#endif /* !SERVER_H_ */
