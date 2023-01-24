/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:20:28 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/24 09:51:11 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest/greatest.h"

extern SUITE(test_atoi);

GREATEST_MAIN_DEFS();
int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

    RUN_SUITE(test_atoi);

	GREATEST_MAIN_END();
}
