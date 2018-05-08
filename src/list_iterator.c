/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** list_iterator
*/

#include <stdlib.h>
#include "list.h"

void list_iter_set_mode(list_iter_t *iter, list_iter_mode_t mode)
{
	iter->li_mode = mode;
	switch (mode) {
	case FWD:
		iter->li_node = iter->li_list->l_start;
		break;
	case BCKW:
		iter->li_node = iter->li_list->l_end;
		break;
	}
}

list_iter_t *list_iter_create(list_t *list, list_iter_mode_t mode)
{
	list_iter_t *iter = malloc(sizeof(list_iter_t));

	if (!iter)
		return (NULL);
	iter->li_list = list;
	list_iter_set_mode(iter, mode);
	return (iter);
}

void *list_iter_next(list_iter_t *iter)
{
	if (!iter->li_node)
		return (NULL);
	switch (iter->li_mode) {
	case FWD:
		iter->li_node = iter->li_node->n_next;
		break;
	case BCKW:
		iter->li_node = iter->li_node->n_prev;
		break;
	}
	if (!iter->li_node)
		return (NULL);
	return (iter->li_node->n_data);
}
