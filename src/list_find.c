/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** list_find
*/

#include <stdlib.h>
#include "list.h"

list_iter_t *list_find_addr(list_t *list, void *addr)
{
	list_iter_t *iter = list_iter_create(list, FWD);

	if (!iter)
		return (NULL);
	while (list_iter_access(iter)) {
		if (list_iter_access(iter) == addr)
			return (iter);
		list_iter_next(iter);
	}
	free(iter);
	return (NULL);
}
