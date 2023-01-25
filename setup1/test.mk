# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 09:24:04 by tdubois           #+#    #+#              #
#    Updated: 2023/01/25 21:59:19 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### FILES

#PREREQS
TSRCS	:=	$(shell find tests -name '*.c')

#TARGETS
TRUNNER	:=	run_tests
TOBJS	:=	$(TSRCS:%.c=build/%.o)
TDEPS	:=	$(TSRCS:%.c=build/%.d)
TDIRS	:=	$(sort $(shell dirname $(TOBJS)))

################################################################################
### CMDS

test: test.build
	@./run_tests;
.PHONY: test

test.build:
	@$(MAKE) -s --jobs=8 $(TRUNNER);
.PHONY: test.build

test.clean:
	@rm -rf build;
	@rm -rf $(NAME);
	@rm -rf $(TRUNNER);
.PHONY: test.clean

#overload flcean to clean test files
fclean: test.clean

test.re: test.clean test
.PHONY: test.re

################################################################################
### TRUNNER TARGET

$(TRUNNER): OBJS	:=	$(filter-out %/main.o, $(OBJS))

$(TRUNNER): $(OBJS) $(TOBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TOBJS) -o $(TRUNNER);

################################################################################
### TOBJS TARGET

$(TDIRS):
	mkdir -p $@;

$(TOBJS): build/%.o: %.c | $$(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@;

-include $(TDEPS)
