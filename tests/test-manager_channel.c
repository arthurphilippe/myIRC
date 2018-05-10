/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** test-manager_channel
*/

#include "criterion/criterion.h"
#include "criterion/assert.h"
#include "manager.h"
#include "server.h"

Test(manager_channel, create) {
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
	manager_channel_create(manager, "main");
	handle_client_create(manager, 1);
	handle_client_create(manager, 2);
	cr_assert(manager->m_handles[0].h_fd == 1);
	cr_assert(manager->m_handles[1].h_fd == 2);

	cr_assert(serv->sv_channels->l_start);
	cr_assert(serv->sv_channels->l_size == 1);
	channel_t *channel = serv->sv_channels->l_start->n_data;
	manager_channel_join(channel, &manager->m_handles[0]);
	manager_channel_join_by_name(manager, "main", &manager->m_handles[1]);

	list_iter_t *iter = list_iter_create(channel->ch_clients, FWD);
	cr_assert_eq(list_iter_access(iter), &manager->m_handles[0]);
	list_iter_next(iter);
	cr_assert_eq(list_iter_access(iter), &manager->m_handles[1]);
	free(iter);

	manager_channel_leave(channel, &manager->m_handles[0]);
	iter = list_iter_create(channel->ch_clients, FWD);
	cr_assert_eq(list_iter_access(iter), &manager->m_handles[1]);
	free(iter);

	handle_client_delete(manager, &manager->m_handles[0]);
	handle_client_delete(manager, &manager->m_handles[1]);
	list_destroy(serv->sv_channels);
	list_destroy(serv->sv_clients);
	serv->sv_channels = NULL;
	serv->sv_clients = NULL;
	free(manager->m_data);
	free(manager);
}
