# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 00:19:04 by tdubois           #+#    #+#              #
#    Updated: 2023/01/21 00:49:13 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### MAKECONF

SHELL		:=	bash
.SHELLFLAGS	:=	-o pipefail -ec

MAKEFLAGS	:=	--no-builtin-rules --no-print-directory --output-sync

.DELETE_ON_ERROR:
.SECONDEXPANSION:

################################################################################
### FILES

#PREREQS
SRCS	:=	$(shell find src -name '*.c')

#TARGETS
NAME	:=	1h1p
OBJS	:=	$(SRCS:src/%.c=build/%.o)
DEPS	:=	$(SRCS:src/%.c=build/%.d)
DIRS	:=	$(sort $(shell dirname $(OBJS)))

################################################################################
### MANDATORY CMDS

all: $(NAME)
.PHONY: all

clean:
	rm -rf build;
.PHONY: clean

fclean:
	rm -rf build;
	rm -rf $(NAME);
.PHONY: fclean

re:	fclean all
.PHONY: re

################################################################################
### CUSTOM CMDS

fast:
	$(MAKE) --jobs=8 all;
.PHONY: fast

refast: fclean fast
.PHONY: refast

################################################################################
### FLAGS

CC			:=	clang
CFLAGS		:=	-Wall -Wextra -Werror -O3
CPPFLAGS	:=	-MP -MMD -Iinclude

################################################################################
### NAME TARGET

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME);

################################################################################
### OBJS TARGET

$(DIRS):
	mkdir -p $@;

$(OBJS): build/%.o: src/%.c | $$(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@;

-include $(DEPS)

################################################################################
### DEV TOOLS

-include test.mk
