/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:43:59 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/24 09:45:55 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest/greatest.h"

#include "1h1p/ft_string.h"

TEST	should_return_123(void)
{
	ASSERT_EQ_FMT(123, ft_atoi("123"), "%i");
	PASS();
}

SUITE(test_atoi)
{
	RUN_TEST(should_return_123);
}
