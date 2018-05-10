/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_destroy
*/

#include <stdlib.h>
#include "manager.h"
#include "server.h"

void manager_channel_destroy(void *ptr)
{
	channel_t *chan = ptr;

	list_destroy(chan->ch_clients);
	free(chan->ch_name);
	free(ptr);
}
