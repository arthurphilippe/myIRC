/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client
*/

#ifndef CLIENT_H_
	#define CLIENT_H_

	#include "list.h"

typedef struct	s_handle_client {
	char	*hc_nickname;
	list_t	*hc_channels;
}		handle_client_t;

#endif /* !CLIENT_H_ */
