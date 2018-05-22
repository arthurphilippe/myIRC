/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client
*/

#include <stdio.h>
#include "manager.h"
#include "handle/client.h"

void irc_msg_client(handle_t *hdl, const char *msg, const char *dest,
			const char *sender)
{
	dprintf(hdl->h_fd, ":%s PRIVMSG %s :%s\r\n",
		sender, dest, msg);
}
