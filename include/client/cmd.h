/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** cmd
*/

#ifndef CMD_H_
	#define CMD_H_

#define CMD_MAX_SIZE 512
#define USER_CMD_SERVER "/server"
#define USER_CMD_NICK "/nick"
#define USER_CMD_LIST "/list"
#define USER_CMD_QUIT "/quit"
#define USER_CMD_EXIT "/exit"
#define USER_CMD_PART "/part"
#define USER_CMD_USER "/user"
#define CMD_MAIN_DELIM " "

/*
**	SERV_AUTOMATIC_ANSWER
*/
#define SERV_CMD_PONG "PING"

char	*client_cmd_extract_arg(const char *cmd, char *delim);
char	*client_cmd_extract_name(const char *str, const char *delim);

#endif /* !CMD_H_ */
