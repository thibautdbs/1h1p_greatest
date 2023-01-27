/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstbubble.test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:37:35 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/27 09:43:52 by tdubois          ###   ########.fr       */
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

TEST	third_element_in_1234(void)
{
	t_lst	lst3 = {.content = 3, .next = NULL};
	t_lst	lst2 = {.content = 2, .next = &lst3};
	t_lst	lst1 = {.content = 1, .next = &lst2};
	t_lst	lst0 = {.content = 0, .next = &lst1};

	t_lst	*lst = &lst0;
	
	ft_lstbubble(&lst, 2);

	CHECK_CALL(ASSERT_LST_EQ_ARR(lst, (int[]){2, 3, 0, 1}, 4));
	PASS();
}

TEST	last_element_in_1234(void)
{
	t_lst	lst3 = {.content = 3, .next = NULL};
	t_lst	lst2 = {.content = 2, .next = &lst3};
	t_lst	lst1 = {.content = 1, .next = &lst2};
	t_lst	lst0 = {.content = 0, .next = &lst1};

	t_lst	*lst = &lst0;
	
	ft_lstbubble(&lst, 3);

	CHECK_CALL(ASSERT_LST_EQ_ARR(lst, (int[]){3, 0, 1, 2}, 4));
	PASS();
}

TEST	first_element_in_1234(void)
{
	t_lst	lst3 = {.content = 3, .next = NULL};
	t_lst	lst2 = {.content = 2, .next = &lst3};
	t_lst	lst1 = {.content = 1, .next = &lst2};
	t_lst	lst0 = {.content = 0, .next = &lst1};

	t_lst	*lst = &lst0;
	
	ft_lstbubble(&lst, 0);

	CHECK_CALL(ASSERT_LST_EQ_ARR(lst, (int[]){0, 1, 2, 3}, 4));
	PASS();
}

TEST	non_existing_element_in_1234(void)
{
	t_lst	lst3 = {.content = 3, .next = NULL};
	t_lst	lst2 = {.content = 2, .next = &lst3};
	t_lst	lst1 = {.content = 1, .next = &lst2};
	t_lst	lst0 = {.content = 0, .next = &lst1};

	t_lst	*lst = &lst0;
	
	ft_lstbubble(&lst, 4);

	CHECK_CALL(ASSERT_LST_EQ_ARR(lst, (int[]){0, 1, 2, 3}, 4));
	PASS();
}

SUITE(test_lstbubble)
{
	RUN_TEST(third_element_in_1234);
	RUN_TEST(last_element_in_1234);
	RUN_TEST(first_element_in_1234);
	RUN_TEST(non_existing_element_in_1234);
}
