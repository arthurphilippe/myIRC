/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** msg
*/

#ifndef MSG_H_
	#define MSG_H_

	#include "manager.h"

void irc_msg_welcome(handle_t *hdl);
void irc_msg_client(handle_t *hdl, const char *msg, const char *dest,
			const char *sender);

#endif /* !MSG_H_ */
