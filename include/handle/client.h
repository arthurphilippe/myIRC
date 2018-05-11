/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client
*/

#ifndef HANDLE_CLIENT_H_
	#define HANDLE_CLIENT_H_

	#include "list.h"

typedef enum	e_log_level {
		NONE,
		NICK,
		USER,
		OK,
}		log_level_t;

typedef struct		s_handle_client {
	char		*hc_nick;
	char		*hc_realname;
	char		*hc_username;
	list_t		*hc_channels;
	log_level_t	*hc_log_level;
}			handle_client_t;

#endif /* !HANDLE_CLIENT_H_ */
