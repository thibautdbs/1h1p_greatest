/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:20:28 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/27 09:42:19 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest/greatest.h"

extern SUITE(test_atoi);
extern SUITE(test_lstpop_back);
extern SUITE(test_lstpop_front);
extern SUITE(test_lstbubble);

GREATEST_MAIN_DEFS();
int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

    RUN_SUITE(test_atoi);
	RUN_SUITE(test_lstpop_back);
	RUN_SUITE(test_lstpop_front);
	RUN_SUITE(test_lstbubble);

	GREATEST_MAIN_END();
}
