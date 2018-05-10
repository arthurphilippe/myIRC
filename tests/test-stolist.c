/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** stolist
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "stolist.h"

Test(stolist, one_word) {
	list_t *words = stolist("toto", " ");

	cr_assert(words);
	cr_assert(words->l_start);
	cr_assert_str_eq(words->l_start->n_data, "toto");
	list_destroy(words);
}

Test(stolist, multiple_words) {
	list_t *words = stolist("toto va a   la plage avec ses khey et\
 sa   serviette", " ");

	cr_assert(words);
	list_iter_t *iter = list_iter_create(words, FWD);
	cr_assert(iter);
	cr_assert_str_eq(list_iter_access(iter), "toto");
	list_iter_next(iter);
	cr_assert_str_eq(list_iter_access(iter), "va");
	list_iter_next(iter);
	cr_assert_str_eq(list_iter_access(iter), "a");
	list_iter_next(iter);
	cr_assert_str_eq(list_iter_access(iter), "la");
	list_iter_next(iter);
	cr_assert_str_eq(list_iter_access(iter), "plage");
	list_iter_next(iter);
	cr_assert_str_eq(list_iter_access(iter), "avec");
	list_iter_next(iter);
	cr_assert_str_eq(list_iter_access(iter), "ses");
	list_iter_next(iter);
	cr_assert_str_eq(list_iter_access(iter), "khey");
	list_iter_next(iter);
	cr_assert_str_eq(list_iter_access(iter), "et");
	list_iter_next(iter);
	cr_assert_str_eq(list_iter_access(iter), "sa");
	list_iter_next(iter);
	cr_assert_str_eq(list_iter_access(iter), "serviette");
	list_iter_next(iter);
	list_destroy(words);
	free(iter);
}
