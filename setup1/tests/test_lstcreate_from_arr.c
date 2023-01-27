/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstcreate_from_arr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:28:28 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/27 11:38:23 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <greatest/greatest.h>

#include <stddef.h>//NULL

#include "1h1p/ft_lst.h"

static t_lst	*actual;

static void	setup(void *data)
{
	(void) data;
	actual = NULL;
}

static void	teardown(void *data)
{
	(void) data;
	ft_lstdestroy(&actual);
}

////////////////////////////////////////////////////////////////////////////////
/// ASSERTIONS

TEST	ASSERT_LST_EQ_ARR(t_lst const *actual, int const *expected, int size)
{
	for (int i = 0; i < size; i++)
	{
		ASSERT_EQ_FMT(actual->content, expected[i], "%i");
		actual = actual->next;
	}
	ASSERT_EQ(NULL, actual);
	PASS();
}

////////////////////////////////////////////////////////////////////////////////
/// TESTS

TEST	basic(void)
{
	char	*argv[] = {"0", "1", "2"};

	actual = ft_lstcreate_from_arr(argv, 3);
	CHECK_CALL(ASSERT_LST_EQ_ARR(actual, (int[]){0, 1, 2}, 3));
	PASS();
}

SUITE(test_lstcreate_from_arr)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(basic);
}
