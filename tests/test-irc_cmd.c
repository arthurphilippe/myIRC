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
