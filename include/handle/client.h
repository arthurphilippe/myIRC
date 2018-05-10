/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client
*/

#ifndef HANDLE_CLIENT_H_
	#define HANDLE_CLIENT_H_

	#include "list.h"

typedef struct	s_handle_client {
	char	*hc_nick;
	list_t	*hc_channels;
}		handle_client_t;

#endif /* !HANDLE_CLIENT_H_ */
