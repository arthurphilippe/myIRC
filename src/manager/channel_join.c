/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_join
*/

#include "manager.h"
#include "server.h"

int manager_channel_join(channel_t *channel, handle_t *client)
{
	return (list_push_back(channel->ch_clients, client));
}
