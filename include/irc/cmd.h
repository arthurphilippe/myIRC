/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** cmd
*/

#ifndef IRC_CMD_H_
	#define IRC_CMD_H_

	#include "manager.h"

typedef struct	s_irc_cmd {
	char	*ic_name;
	void	(*ic_func)(manager_t *, handle_t *, const char *cmd);
}		irc_cmd_t;

#endif /* !IRC_CMD_H_ */
