/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:43:59 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/27 08:05:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest/greatest.h"

#include "1h1p/ft_string.h"

TEST	only_digits(void)
{
	ASSERT_EQ_FMT(123, ft_atoi("123"), "%i");
	PASS();
}

TEST	only_non_digits(void)
{
	ASSERT_EQ_FMT(0, ft_atoi("foo"), "%i");
	PASS();
}

TEST	leading_plus_sign(void)
{
	ASSERT_EQ_FMT(123, ft_atoi("+123"), "%i");
	PASS();
}

TEST	leading_minus_sign(void)
{
	ASSERT_EQ_FMT(-123, ft_atoi("-123"), "%i");
	PASS();
}

TEST	leading_spaces(void)
{
	ASSERT_EQ_FMT(123, ft_atoi("  123"), "%i");
	ASSERT_EQ_FMT(123, ft_atoi("  +123"), "%i");
	ASSERT_EQ_FMT(-123, ft_atoi("  -123"), "%i");
	PASS();
}

TEST	leading_spaces_and_tabs(void)
{
	ASSERT_EQ_FMT(123, ft_atoi(" \t123"), "%i");
	ASSERT_EQ_FMT(123, ft_atoi(" \t+123"), "%i");
	ASSERT_EQ_FMT(-123, ft_atoi(" \t-123"), "%i");
	PASS();
}

TEST	trailing_spaces(void)
{
	ASSERT_EQ_FMT(123, ft_atoi("123 "), "%i");
	ASSERT_EQ_FMT(123, ft_atoi("+123 "), "%i");
	ASSERT_EQ_FMT(-123, ft_atoi("-123 "), "%i");
	PASS();
}

TEST	trailing_non_digits(void)
{
	ASSERT_EQ_FMT(123, ft_atoi("123foo"), "%i");
	ASSERT_EQ_FMT(123, ft_atoi("+123foo"), "%i");
	ASSERT_EQ_FMT(-123, ft_atoi("-123foo"), "%i");
	PASS();
}


SUITE(test_atoi)
{
	RUN_TEST(only_digits);
	RUN_TEST(only_non_digits);
	RUN_TEST(leading_plus_sign);
	RUN_TEST(leading_minus_sign);
	RUN_TEST(leading_spaces);
	RUN_TEST(leading_spaces_and_tabs);
	RUN_TEST(trailing_spaces);
	RUN_TEST(trailing_non_digits);
}
