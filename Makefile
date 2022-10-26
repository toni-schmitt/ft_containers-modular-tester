# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschmitt <tschmitt@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 21:58:57 by tschmitt          #+#    #+#              #
#    Updated: 2022/10/26 22:17:17 by tschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################################################
# Configure this to your ft_containers Directory #
FT_CONTAINERS_PATH = ../ft_containers/ft_containers
##################################################


TESTER_DIR = ./tests
TESTER_BIN = $(TESTER_DIR)/containers_tester
INCFLAG := -I$(realpath $(FT_CONTAINERS_PATH))

TOP_TARGETS := all clean fclean re test help vector map set stack no_bench

$(TOP_TARGETS): $(TESTER_DIR)

$(TESTER_DIR):
	@$(MAKE) --no-print-directory -C $@ $(MAKECMDGOALS) INCFLAGS=$(INCFLAG)
#	@cp $(TESTER_BIN) $(notdir $(TESTER_BIN))

.PHONY: $(TOP_TARGETS) $(TESTER_DIR)