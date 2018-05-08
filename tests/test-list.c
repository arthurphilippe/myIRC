/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** test-list
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

Test(list, empty) {
	list_t *list = list_create(free);

	cr_assert_eq(list_size(list), 0);
	cr_assert_eq(list_get_back(list), NULL);
	cr_assert_eq(list_get_front(list), NULL);
	list_pop_back(list);
	list_pop_front(list);

	list_destroy(list);
}

Test(list, nullDestructor) {
	list_t *list = list_create(NULL);

	cr_assert_eq(list_size(list), 0);
	cr_assert_eq(list_get_back(list), NULL);
	cr_assert_eq(list_get_front(list), NULL);

	char *tmp = strdup("j'aime les pates");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	cr_log_info("1st");
	list_push_back(list, tmp);
	list_pop_back(list);

	cr_log_info("2nd");
	list_push_front(list, tmp);
	list_pop_front(list);

	cr_log_info("3nd");
	list_push_front(list, tmp);

	cr_log_info("destroy");
	list_destroy(list);
	cr_log_info("free");
	free(tmp);
}

Test(list, pushback) {
	list_t *list = list_create(free);

	cr_assert_eq(list_size(list), 0);

	char *tmp = strdup("j'aime les pates");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_back(list, tmp);

	tmp = strdup("toto");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_back(list, tmp);

	cr_assert_eq(list_size(list), 2);

	list_destroy(list);
}

Test(list, pushfront) {
	list_t *list = list_create(free);

	cr_assert_eq(list_size(list), 0);

	char *tmp = strdup("j'aime les pates");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_front(list, tmp);

	tmp = strdup("toto");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_front(list, tmp);

	cr_assert_eq(list_size(list), 2);

	list_destroy(list);
}

Test(list, frontAndBack) {
	list_t *list = list_create(free);

	cr_assert_eq(list_size(list), 0);

	char *tmp = strdup("j'aime les pates");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_front(list, tmp);

	tmp = strdup("bah euh");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_front(list, tmp);

	tmp = strdup("toto");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_front(list, tmp);

	cr_assert_eq(list_size(list), 3);

	cr_assert_str_eq(list_get_front(list), "toto");
	cr_assert_str_eq(list_get_back(list), "j'aime les pates");

	list_destroy(list);
}

Test(list, popbackAndPopFront) {
	list_t *list = list_create(free);

	cr_assert_eq(list_size(list), 0);

	char *tmp = strdup("j'aime les pates");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_front(list, tmp);

	tmp = strdup("bah euh");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_front(list, tmp);

	tmp = strdup("toto");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_front(list, tmp);

	cr_assert_eq(list_size(list), 3);

	cr_assert_str_eq(list_get_front(list), "toto");
	cr_assert_str_eq(list_get_back(list), "j'aime les pates");

	list_pop_back(list);
	cr_assert_eq(list_size(list), 2);
	cr_assert_str_eq(list_get_back(list), "bah euh");
	list_pop_front(list);

	cr_assert_str_eq(list_get_back(list), "bah euh");
	cr_assert_str_eq(list_get_front(list), "bah euh");
	cr_assert_eq(list_size(list), 1);

	tmp = strdup("toto");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_front(list, tmp);
	cr_assert_eq(list_size(list), 2);

	list_pop_back(list);

	cr_assert_eq(list_size(list), 1);
	cr_assert_str_eq(list_get_back(list), "toto");
	cr_assert_str_eq(list_get_front(list), "toto");
	list_pop_back(list);

	cr_assert_eq(list_size(list), 0);
	tmp = strdup("tomate");
	if (!tmp) {
		cr_log_error("malloc failure");
		cr_assert_fail();
	}
	list_push_back(list, tmp);
	cr_assert_eq(list_size(list), 1);
	list_pop_front(list);
	cr_assert_eq(list_size(list), 0);
	list_destroy(list);
}
