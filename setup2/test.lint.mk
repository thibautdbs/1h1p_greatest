# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.lint.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 23:34:58 by tdubois           #+#    #+#              #
#    Updated: 2023/01/26 00:38:10 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LFILES	:=	$(shell find src -name '*.c')			\
			$(shell find include/1h1p -name '*.h')	\

test.lint:
	@! norminette $(LFILES) | grep Error;
.PHONY: test.lint

test.lint.log:
	@norminette $(LFILES);
.PHONY: test.lint.log
