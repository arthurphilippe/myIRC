/*
** EPITECH PROJECT, 2018
** myIRC
** File description:
** privmsg
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "client/client.h"
#include "manager.h"
#include "stolist.h"

int msg_cmd(manager_t *manager, char *arg)
{
	list_t *list = stolist(arg, " ");
	list_iter_t *iterator = list_iter_create(list, FWD);
	char *tmp = NULL;

	tmp = list_iter_access(iterator);
	if (tmp[0] == '#') {
	} else {
		// 'send a file to a user'
	}
	free(iterator);
	list_destroy(list);
}
