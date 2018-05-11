/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** str_to_list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

static int push_back_substr(list_t *list, const char *str,
				const char *spacers)
{
	size_t cpy_size = strcspn(str, spacers);
	char *tmp = calloc(sizeof(char), cpy_size + 1);

	if (!tmp)
		return (-1);
	strncpy(tmp, str, cpy_size);
	if (list_push_back(list, tmp) == LIST_OK)
		return (cpy_size);
	return (LIST_ERR);
}

list_t *stolist(const char *str, const char *spacers)
{
	list_t *list = list_create(free);
	int i = 0;
	int ret;

	if (!list)
		return (NULL);
	do {
		ret = push_back_substr(list, &str[i], spacers);
		if (ret == LIST_ERR) {
			list_destroy(list);
			return (NULL);
		}
		i += ret;
		ret = strspn(&str[i], spacers);
		i += ret;
	} while (str[i]);
	return (list);
}
