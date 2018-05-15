/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** cmd
*/

#ifndef IRC_CMD_H_
	#define IRC_CMD_H_

	#include "manager.h"
	#include "list.h"

typedef struct	s_irc_cmd {
	char	*ic_name;
	void	(*ic_func)(manager_t *, handle_t *, list_t *args);
}		irc_cmd_t;

void irc_cmd_run(manager_t *manager, handle_t *hdl, const char *cmd);

/*
** Parsing functions
*/
char *irc_cmd_get_name(list_t *split_cmd);
void irc_cmd_strip_to_args(list_t *cmd);

/*
** Actual IRC commands
*/
void irc_cmd_user(manager_t *manager, handle_t *hdl, list_t *arg);
void irc_cmd_nick(manager_t *manager, handle_t *hdl, list_t *arg);
void irc_cmd_join(manager_t *manager, handle_t *hdl, list_t *arg);
void irc_cmd_part(manager_t *manager, handle_t *hdl, list_t *arg);
void irc_cmd_names(manager_t *manager, handle_t *hdl, list_t *arg);
void irc_cmd_list(manager_t *manager, handle_t *hdl, list_t *arg);
void irc_cmd_privmsg(manager_t *manager, handle_t *hdl, list_t *arg);

#endif /* !IRC_CMD_H_ */
