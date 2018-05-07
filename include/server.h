/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** server
*/

#ifndef SERVER_H_
	#define SERVER_H_

typedef enum	e_handle_type {
	H_FREE = 0,
	H_PORT,
	H_CLIENT,
}		handle_type_t;

typedef void (*handle_func_t)();

typedef struct		s_handle {
	int		h_fd;
	handle_type_t	h_type;
	handle_func_t	h_read;
	handle_func_t	h_write;
}			handle_t;

#define MAX_HANDLES 255
#define SERV_RET_OK 0
#define SERV_RET_ERR -1
#define SERV_BACKLOG 42
#ifndef NULL
	#define NULL (void *) 0
#endif

typedef struct		s_server {
	handle_t	sv_handles[MAX_HANDLES];
	int		sv_port;
}			server_t;

/*
** Prototypes
*/
handle_t *server_handle_get_free(server_t *serv);
int server_port_listen(server_t *serv, int port);

#endif /* !SERVER_H_ */
