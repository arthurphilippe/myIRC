/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** test-handle_client
*/

#include "criterion/criterion.h"
#include "criterion/assert.h"
#include "manager.h"
#include "server.h"
#include "handle/client.h"

Test(handle_client, nickname) {
	handle_t client;
	handle_client_t data;

	client.h_data = &data;
	data.hc_nick = NULL;
	handle_client_set_nick(&client, "toto");
	cr_assert_str_eq(data.hc_nick, "toto");
	handle_client_set_nick(&client, "tartufle");
	cr_assert_str_eq(data.hc_nick, "tartufle");
	free(data.hc_nick);
}
