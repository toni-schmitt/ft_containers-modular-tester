# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschmitt <tschmitt@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 19:38:06 by tschmitt          #+#    #+#              #
#    Updated: 2022/10/26 22:12:46 by tschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

BIN = ./containers_tester

SRC_DIR = ./src
BUILD_DIR = ./build

SOURCES = $(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
DEPENDS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.d, $(SOURCES))

all: $(BIN)

-include $(DEPENDS)

$(BIN): TYPE=-DTYPE=int
$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP $(INCFLAGS) $(BENCH) $(TYPE) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(BIN)

.NOTPARALLEL:
re: fclean all

run: all
	$(BIN)

test: all
	$(BIN) $(C) $(CONTAINER) $(T) $(TEST)

help:
	@printf "Usage:\n"
	@printf "\t'make test':\t\t\t\tRun all Tests\n"
	@printf "\t'make test C=[Container]':\t\tRun Test for specific Container\n"
	@printf "\t'make test C=[Container] T=[Test]':\tRun specific Test for specific Container\n"
	@printf "\t'make no_bench':\t\t\tRun all Tests without Benchmark\n"
	@printf "\t'make extra_bench':\t\tRun all Tests and print execution Time\n"

config: config_help
config_help:
	@printf "Configuration Help:\n"
	@printf "Configuration in Makefile:\n"
	@printf "\tChange FT_CONTAINERS_PATH to your path (where your .hpp files are)\n"
	@printf "Directory Structure:\n"
	@printf "\t/ft_containers\n"
	@printf "\t|-- 'ft_containers' (where your .hpp files are)\n"
	@printf "\t|-- ft_containers-modular-tester\n"

vector: C=vector
vector: test

map: C=map
map: test

set: C=set
set: test

stack: C=stack
stack: test

no_bench: BENCH=-DNO_BENCH
no_bench: re test

extra_bench: BENCH=-DEXTRA_BENCH
extra_bench: re test

.PHONY: all clean fclean re test help vector map set stack no_bench
