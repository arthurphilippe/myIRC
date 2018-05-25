/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** test-manager_client
*/

#include "criterion/criterion.h"
#include "criterion/assert.h"
#include "manager.h"
#include "server.h"

Test(manager_client, one_client)
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
	handle_client_create(manager, 2);
	cr_assert(manager->m_handles[0].h_fd == 2);

	list_iter_t *iter = list_find_addr(serv->sv_clients, &manager->m_handles[0]);
	cr_assert(iter);
	cr_assert_eq(list_iter_access(iter), &manager->m_handles[0]);

	void *save = &manager->m_handles[0];
	handle_client_delete(manager, &manager->m_handles[0]);

	free(iter);
	iter = list_find_addr(serv->sv_clients, save);
	cr_assert(!iter);
	cr_assert_eq(manager->m_handles[0].h_type, H_FREE);
}

Test(manager_client, multi_client)
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

	list_iter_t *iter = list_find_addr(serv->sv_clients, &manager->m_handles[0]);
	cr_assert(iter);
	cr_assert_eq(list_iter_access(iter), &manager->m_handles[0]);

	void *save = &manager->m_handles[0];
	handle_client_delete(manager, &manager->m_handles[0]);

	free(iter);
	iter = list_find_addr(serv->sv_clients, save);
	cr_assert(!iter);
	cr_assert_eq(manager->m_handles[0].h_type, H_FREE);

	save = &manager->m_handles[1];
	handle_client_delete(manager, &manager->m_handles[1]);
	iter = list_find_addr(serv->sv_clients, save);
	cr_assert(!iter);
	cr_assert_eq(manager->m_handles[1].h_type, H_FREE);
}

