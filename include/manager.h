/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** manager
*/

#ifndef HANDLE_MANAGER_H_
	#define HANDLE_MANAGER_H_

typedef enum	e_handle_type {
	H_FREE = 0,
	H_PORT,
	H_CLIENT,
}		handle_type_t;

typedef void (*handle_func_t)();

typedef union	u_m_data {
	void	*hd_generic_ptr;
}		m_data_t;

typedef struct		s_handle {
	int		h_fd;
	handle_type_t	h_type;
	handle_func_t	h_read;
	handle_func_t	h_write;
}			handle_t;

#define MAX_HANDLES 255
#define MANAGER_RET_OK 0
#define MANAGER_RET_ERR -1
#define MANAGER_BACKLOG 42
#ifndef NULL
	#define NULL (void *) 0
#endif

typedef struct		s_manager {
	handle_t	m_handles[MAX_HANDLES];
	m_data_t	m_data;
}			manager_t;

manager_t	*manager_create();
manager_t	*manager_create_port(int port);
void		manager_loop(manager_t *serv);

void handle_port_read(manager_t *serv, handle_t *port_hdl);
void handle_client_read(manager_t *serv, handle_t *port_hdl);

handle_t	*manager_handle_get_free(manager_t *serv);
handle_t	*manager_handle_get_from_fd(manager_t *serv, int fd);
int		handle_port_create(manager_t *serv, int port);
void		handle_port_read(manager_t *serv, handle_t *port_hdl);

void		handle_client_read(manager_t *serv, handle_t *client_hdl);


#endif /* !manager_H_ */
