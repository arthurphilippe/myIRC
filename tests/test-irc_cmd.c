/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** test-irc_cmd
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <stolist.h>
#include "irc/cmd.h"
#include "handle/client.h"

Test(irc_cmd, strip_to_args_prefix) {
	list_t *cmd = stolist(
		":ignoredprefix name voiture otoctone", " ");

	irc_cmd_strip_to_args(cmd);

	list_iter_t *iter = list_iter_create(cmd, FWD);
	char *tmp = list_iter_next(iter);

	cr_assert_str_eq(tmp, "voiture");
	tmp = list_iter_next(iter);
	cr_assert_str_eq(tmp, "otoctone");
	free(iter);
	list_destroy(cmd);
}

Test(irc_cmd, strip_to_args_noprefix) {
	list_t *cmd = stolist(
		"name voiture otoctone", " ");

	irc_cmd_strip_to_args(cmd);

	list_iter_t *iter = list_iter_create(cmd, FWD);
	char *tmp = list_iter_next(iter);

	cr_assert_str_eq(tmp, "voiture");
	tmp = list_iter_next(iter);
	cr_assert_str_eq(tmp, "otoctone");
	free(iter);
	list_destroy(cmd);
}

Test(irc_cmd, get_name_no_prefix) {
	list_t *cmd = stolist(
		"name voiture otoctone", " ");
	char *name_cmd = irc_cmd_get_name(cmd);

	cr_assert_str_eq(name_cmd, "name");
	free(name_cmd);
	list_destroy(cmd);
}

Test(irc_cmd, get_name_prefix) {
	list_t *cmd = stolist(
		":qsdiofjqsmiojazemroifjqzemrlfj name voiture otoctone", " ");
	char *name_cmd = irc_cmd_get_name(cmd);

	cr_assert_str_eq(name_cmd, "name");
	free(name_cmd);
	list_destroy(cmd);
}

void irc_cmd_user_extract(handle_t *hdl, list_t *arg);

Test(irc_cmd_user, extraction) {
	list_t *cmd = stolist_spe_irc("cheap noop noop :Jaffar Tram", " ");
	handle_t handle;
	handle.h_fd = 1;
	handle_client_t client;

	handle.h_data = &client;
	client.hc_nick = NULL;
	client.hc_realname = NULL;
	client.hc_username = NULL;
	client.hc_log_level = NONE;
	irc_cmd_user_extract(&handle, cmd);
	cr_assert_str_eq(client.hc_realname, "Jaffar Tram");
	cr_assert_str_eq(client.hc_username, "cheap");
	cr_assert_eq(client.hc_log_level, USER);
	client.hc_log_level = NICK;
	irc_cmd_user_extract(&handle, cmd);
	list_destroy(cmd);
	free(client.hc_realname);
	free(client.hc_username);
	free(client.hc_nick);
}

void irc_cmd_user(manager_t *manager, handle_t *hdl, list_t *arg);
void irc_cmd_nick(manager_t *manager, handle_t *hdl, list_t *arg);

Test(irc_cmd_user, whole_ok) {
	list_t *cmd = stolist_spe_irc("cheap noop noop :Jaffar Tram", " ");
	handle_t handle;
	handle.h_fd = 1;
	manager_t manager;
	handle_client_t client;

	cr_expect_eq(cmd->l_size, 4);
	handle.h_data = &client;
	client.hc_nick = NULL;
	client.hc_realname = NULL;
	client.hc_username = NULL;
	client.hc_log_level = NONE;
	irc_cmd_user(&manager, &handle, cmd);
	cr_assert_str_eq(client.hc_realname, "Jaffar Tram");
	cr_assert_str_eq(client.hc_username, "cheap");
	cr_assert_eq(client.hc_log_level, USER);
	list_destroy(cmd);
	cmd = stolist_spe_irc("", "");
	irc_cmd_nick(&manager, &handle, cmd);

	list_destroy(cmd);
	cmd = stolist_spe_irc("cheapux", "");
	irc_cmd_nick(&manager, &handle, cmd);
	irc_cmd_nick(&manager, &handle, cmd);
	cr_assert_eq(client.hc_log_level, OK);

	client.hc_log_level = NONE;
	irc_cmd_nick(&manager, &handle, cmd);
	list_destroy(cmd);
	cmd = stolist_spe_irc("cheap noop noop :Jaffar Tram", " ");
	irc_cmd_user(&manager, &handle, cmd);
	cr_assert_eq(client.hc_log_level, OK);
	list_destroy(cmd);
	free(client.hc_realname);
	free(client.hc_username);
	free(client.hc_nick);
}

Test(irc_cmd_user, whole_param_err) {
	list_t *cmd = stolist_spe_irc("cheap noop :Jaffar Tram", " ");
	handle_t handle;
	handle.h_fd = 1;
	manager_t manager;
	handle_client_t client;

	cr_expect_eq(cmd->l_size, 3);
	handle.h_data = &client;
	client.hc_nick = NULL;
	client.hc_realname = NULL;
	client.hc_username = NULL;
	client.hc_log_level = NONE;
	irc_cmd_user(&manager, &handle, cmd);
	cr_assert_eq(client.hc_realname, NULL);
	cr_assert_eq(client.hc_username, NULL);
	cr_assert_eq(client.hc_log_level, NONE);
	list_destroy(cmd);
	free(client.hc_realname);
	free(client.hc_username);
	free(client.hc_nick);
}

Test(irc_cmd_user, whole_param_relog) {
	list_t *cmd = stolist_spe_irc("cheap noop noop :Jaffar Tram", " ");
	handle_t handle;
	handle.h_fd = 1;
	manager_t manager;
	handle_client_t client;

	cr_expect_eq(cmd->l_size, 4);
	handle.h_data = &client;
	client.hc_nick = NULL;
	client.hc_realname = NULL;
	client.hc_username = NULL;
	client.hc_log_level = NONE;
	irc_cmd_user(&manager, &handle, cmd);
	cr_assert_str_eq(client.hc_realname, "Jaffar Tram");
	cr_assert_str_eq(client.hc_username, "cheap");
	cr_assert_eq(client.hc_log_level, USER);
	client.hc_log_level = NICK;
	irc_cmd_user(&manager, &handle, cmd);
	cr_assert_eq(client.hc_log_level, OK);
	list_destroy(cmd);
	cmd = stolist_spe_irc("cheap noop noop :Kappa wa Kawai", " ");
	irc_cmd_user(&manager, &handle, cmd);
	cr_assert_str_eq(client.hc_realname, "Jaffar Tram");
	cr_assert_str_eq(client.hc_username, "cheap");
	cr_assert_eq(client.hc_log_level, OK);
	list_destroy(cmd);
	free(client.hc_realname);
	free(client.hc_username);
	free(client.hc_nick);
}
