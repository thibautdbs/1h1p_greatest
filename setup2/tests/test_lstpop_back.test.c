/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstpop_back.test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:06:41 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/27 09:02:33 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <greatest/greatest.h>

#include <stddef.h>//NULL

#include "1h1p/ft_lst.h"

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

TEST	pop_from_list_of_3(void)
{
	t_lst	lst2 = {.content = 2, .next = NULL};
	t_lst	lst1 = {.content = 1, .next = &lst2};
	t_lst	lst0 = {.content = 0, .next = &lst1};

	t_lst	*lst = &lst0;
	
	t_lst	*last = ft_lstpop_back(&lst);

	CHECK_CALL(ASSERT_LST_EQ_ARR(last, (int[]){2}, 1));
	CHECK_CALL(ASSERT_LST_EQ_ARR(lst, (int[]){0, 1}, 2));
	PASS();
}

TEST	pop_from_list_of_2(void)
{
	t_lst	lst1 = {.content = 1, .next = NULL};
	t_lst	lst0 = {.content = 0, .next = &lst1};

	t_lst	*lst = &lst0;
	
	t_lst	*last = ft_lstpop_back(&lst);

	CHECK_CALL(ASSERT_LST_EQ_ARR(last, (int[]){1}, 1));
	CHECK_CALL(ASSERT_LST_EQ_ARR(lst, (int[]){0}, 1));
	PASS();
}

TEST	pop_from_list_of_1(void)
{
	t_lst	lst0 = {.content = 0, .next = NULL};

	t_lst	*lst = &lst0;
	
	t_lst	*last = ft_lstpop_back(&lst);

	CHECK_CALL(ASSERT_LST_EQ_ARR(last, (int[]){0}, 1));
	ASSERT_EQ(NULL, lst);
	PASS();
}

TEST	pop_from_empty_list(void)
{
	t_lst	*lst = NULL;
	
	t_lst	*last = ft_lstpop_back(&lst);

	ASSERT_EQ(NULL, lst);
	ASSERT_EQ(NULL, last);
	PASS();
}

SUITE(test_lstpop_back)
{
	RUN_TEST(pop_from_list_of_3);
	RUN_TEST(pop_from_list_of_2);
	RUN_TEST(pop_from_list_of_1);
	RUN_TEST(pop_from_empty_list);
}
