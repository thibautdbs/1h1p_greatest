# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 23:33:48 by tdubois           #+#    #+#              #
#    Updated: 2023/01/25 23:43:16 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include test.unit.mk test.lint.mk

test: test.unit test.lint
.PHONY: test

test.log: test.unit.log test.lint.log
.PHONY: test.log
