/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** welcome
*/

#include <stdio.h>
#include "manager.h"
#include "handle/client.h"

void irc_msg_welcome(handle_t *hdl)
{
	handle_client_t *client = hdl->h_data;

	dprintf(hdl->h_fd, ":myirc_server 001 %s welcome!\r\n", client->hc_nick);
	dprintf(hdl->h_fd, ":myirc_server PING :%s\r\n", client->hc_nick);
}
