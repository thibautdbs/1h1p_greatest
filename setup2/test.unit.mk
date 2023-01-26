# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.unit.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 09:24:04 by tdubois           #+#    #+#              #
#    Updated: 2023/01/26 01:51:00 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### FILES

#PREREQS
TSRCS		:=	$(shell find tests -name '*.test.c')

#TARGETS
TOBJS		:=	$(TSRCS:%.c=build/%.o)
TDEPS		:=	$(TSRCS:%.c=build/%.d)
TDIRS		:=	$(sort $(shell dirname $(TOBJS)))

TARCHIVE	:=	build/$(NAME).a
TMAINS		:=	$(TSRCS:%.c=build/%.main.c)
TRUNNERS	:=	$(TSRCS:%.c=build/%.out)
TLOGS		:=	$(TSRCS:%.c=build/%.log)

################################################################################
### CMDS

test.unit:
	@rm -f $(TLOGS);
	@$(MAKE) -s -k --jobs=8 $(TLOGS);
.PHONY: test.unit

test.unit.log:
	-@$(MAKE) -s test.unit;
	-@find build/tests -name '*.log' | xargs -r -L1 cat;
.PHONY: test.unit.log

test.unit.select:
	@. scripts/select_test;
.PHONY: test.unit.select

test.unit.gdb:
	@. scripts/select_test --gdb;
.PHONY: test.unit.gdb

test.unit.clean:
	@rm -rf build;
	@rm -rf $(NAME);
.PHONY: test.unit.clean

#overload flcean to clean test files
fclean: test.unit.clean

test.unit.re: test.unit.clean test.unit
.PHONY: test.unit.re

################################################################################
### TDIRS TARGET

$(TDIRS):
	mkdir -p $@;

################################################################################
### TOBJS TARGET

$(TOBJS): build/%.o: %.c | $$(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@;

-include $(TDEPS)

################################################################################
### TARCHIVE TARGET

$(TARCHIVE): OBJS	:=	$(filter-out %/main.o, $(OBJS))

$(TARCHIVE): CFLAGS	:=	-Wall -Wextra -Wno-unused-result -Werror -ggdb3

$(TARCHIVE): $(OBJS)
	ar rcs $(TARCHIVE) $(OBJS);

################################################################################
### TMAINS TARGET

$(TMAINS): build/%.main.c: %.c | $$(@D)
	. scripts/mkmain $< > $@;

################################################################################
### TRUNNERS TARGET

$(TRUNNERS): CFLAGS		:=	-Wall -Wextra -Wno-unused-result -Werror -ggdb3
$(TRUNNERS): CPPFLAGS	+=	-Itests -Isrc
$(TRUNNERS): LDFLAGS	:=	-L$(dir $(TARCHIVE)) -l:$(notdir $(TARCHIVE))

$(TRUNNERS): build/%.out: build/%.main.c %.c $(TARCHIVE) | $$(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< $*.c $(LDFLAGS) -o $@;

################################################################################
### TLOGS TARGET

$(TLOGS): TIMEOUT	:=	timeout						\
							--verbose				\
							--kill-after=5s			\
							3s						\

$(TLOGS): VALGRIND	:=	valgrind					\
							--quiet					\
							--leak-check=full		\
							--show-reachable=yes	\
							--error-exitcode=1		\

$(TLOGS): %.log: %.out | $$(@D)
	$(TIMEOUT) $(VALGRIND) $< >&$@ || ( cat $@; false);
