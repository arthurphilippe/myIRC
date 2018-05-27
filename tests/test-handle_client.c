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

Test(handle_client, nickname)
{
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

Test(handle_client_find, complete)
{
	manager_t *manager = manager_create();

	if (!manager) {
		cr_log_error("failed malloc");
		cr_assert_fail();
	}
	manager->m_data = malloc(sizeof(server_t));
	if (!manager->m_data) {
		cr_log_error("failed malloc");
		cr_assert_fail();
	}
	server_t *serv = manager->m_data;
	serv->sv_channels = list_create(manager_channel_destroy);
	serv->sv_clients = list_create(NULL);
	cr_assert(serv->sv_channels && serv->sv_clients);
	handle_client_create(manager, 1);
	handle_client_create(manager, 2);
	cr_assert(manager->m_handles[0].h_fd == 1);
	cr_assert(manager->m_handles[1].h_fd == 2);

	handle_client_t data1;
	handle_client_t data2;

	data1.hc_nick = "toto";
	data2.hc_nick = "k2000";
	manager->m_handles[0].h_data = &data1;
	manager->m_handles[1].h_data = &data2;

	handle_t *res = handle_client_find(manager, "k2000");
	handle_client_t *res_data = res->h_data;
	cr_assert_str_eq(res_data->hc_nick, data2.hc_nick);

	res = handle_client_find(manager, "toto");
	res_data = res->h_data;
	cr_assert_str_eq(res_data->hc_nick, data1.hc_nick);

	res = handle_client_find(manager, "kappa");
	cr_assert(!res);
}
