/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** list
*/

#ifndef LIST_H_
	#define LIST_H_

	#include "stddef.h"

typedef struct	s_list_node {
	void	*n_data;
	void	*n_next;
	void	*n_prev;
}		list_node_t;

typedef struct		s_list {
	list_node_t	*l_start;
	list_node_t	*l_end;
	size_t		l_size;
	void		(*l_destructor)(void *);
}			list_t;

typedef enum	e_list_iter_mode {
		FWD,
		BCKW,
}		list_iter_mode_t;

typedef struct			s_list_iterator {
	list_t			*li_list;
	list_node_t		*li_node;
	list_iter_mode_t	li_mode;
}				list_iter_t;


/*
** Prototypes
*/

list_t *list_create(void (*data_destructor)(void *));
void list_destroy(list_t *list);
void list_node_add_first(list_t *list, list_node_t *fst_node);
list_t *list_push_back(list_t *list, void *payload);
list_t *list_push_front(list_t *list, void *payload);
void *list_get_front(list_t *list);
void *list_get_back(list_t *list);
size_t list_size(list_t *list);
void list_pop_front(list_t *list);
void list_pop_back(list_t *list);

#endif /* !LIST_H_ */
