/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** list
*/

#include <stdlib.h>
#include "list.h"

list_t *list_create(void (*data_destructor)(void *))
{
	list_t *new_list;

	new_list = malloc(sizeof(list_t));
	if (!new_list)
		return (NULL);
	new_list->l_start = NULL;
	new_list->l_end = NULL;
	new_list->l_size = 0;
	new_list->l_destructor = data_destructor;
	return (new_list);
}

static void list_node_destroy_rec(list_node_t *node,
					void (*data_destructor)(void *))
{
	if (node->n_next)
		list_node_destroy_rec(node->n_next, data_destructor);
	if (data_destructor)
		data_destructor(node->n_data);
	free(node);
}

void list_destroy(list_t *list)
{
	if (list->l_start)
		list_node_destroy_rec(list->l_start, list->l_destructor);
	free(list);
}

void list_node_add_first(list_t *list, list_node_t *fst_node)
{
	fst_node->n_next = NULL;
	fst_node->n_prev = NULL;
	list->l_start = fst_node;
	list->l_end = fst_node;
}

list_t *list_push_back(list_t *list, void *payload)
{
	list_node_t *new_node = malloc(sizeof(list_node_t));

	if (!new_node)
		return (NULL);
	new_node->n_data = payload;
	if (list->l_end == NULL) {
		list_node_add_first(list, new_node);
	} else {
		list->l_end->n_next = new_node;
		new_node->n_prev = list->l_end;
		new_node->n_next = NULL;
		list->l_end = new_node;
	}
	list->l_size += 1;
	return (list);
}

list_t *list_push_front(list_t *list, void *payload)
{
	list_node_t *new_node = malloc(sizeof(list_node_t));

	if (!new_node)
		return (NULL);
	new_node->n_data = payload;
	if (list->l_start == NULL) {
		list_node_add_first(list, new_node);
	} else {
		list->l_start->n_prev = new_node;
		new_node->n_next = list->l_start;
		new_node->n_prev = NULL;
		list->l_start = new_node;
	}
	list->l_size += 1;
	return (list);
}

void *list_get_front(list_t *list)
{
	if (list->l_start)
		return (list->l_start->n_data);
	return (NULL);
}

void *list_get_back(list_t *list)
{
	if (list->l_end)
		return (list->l_end->n_data);
	return (NULL);
}

size_t list_size(list_t *list)
{
	return list->l_size;
}

void list_pop_front(list_t *list)
{
	list_node_t *old_start = list->l_start;

	if (list->l_start) {
		list->l_start = list->l_start->n_next;
		if (list->l_start)
			list->l_start->n_prev = NULL;
		else
			list->l_end = NULL;
		if (list->l_destructor)
			list->l_destructor(old_start->n_data);
		free(old_start);
	}
	list->l_size -= 1;
}

void list_pop_back(list_t *list)
{
	list_node_t *old_end = list->l_end;

	if (old_end) {
		list->l_end = list->l_end->n_prev;
		if (list->l_end)
			list->l_end->n_next = NULL;
		else
			list->l_start = NULL;
		if (list->l_destructor)
			list->l_destructor(old_end->n_data);
		free(old_end);
	}
	list->l_size -= 1;
}
