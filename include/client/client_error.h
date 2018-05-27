/*
** EPITECH PROJECT, 2018
** Client IRC
** File description:
** Errors Headers
*/

#ifndef CLIENT_ERROR_H_
	#define CLIENT_ERROR_H_

	#define PRINT_USAGE "USAGE: ./client $host $port"
	#define MALLOC_FAIL "Memory Allocation Failed"
	#define ARG2_FAIL ": argument must contain numericals characters"
	#define WRONG_ARG_NBR "Invalid Arugment"
	#define CLIENT_NOT_CONNECTED "Not connected to server"

int ret_int_client(int ret, const char *msg,
			const char *what, const char *end);


#endif /* !CLIENT_ERROR_H_ */
