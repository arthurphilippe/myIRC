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
#define CMD_MAIN_DELIM " "

char	*client_cmd_extract_arg(const char *cmd, char *delim);
char	*client_cmd_extract_name(const char *str, const char *delim);

#endif /* !CMD_H_ */
