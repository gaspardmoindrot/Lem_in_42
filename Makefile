# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 14:03:16 by rbeaufre          #+#    #+#              #
#    Updated: 2019/11/19 17:45:19 by rbeaufre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

MAKEFILE = Makefile
BIN_DIR = .
SRC_DIR = .
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_RAW =  get_next_line.c lem-in.c print_adjacent_list.c \
			initialize_adjacent_list.c free_adjacent_list.c \
			parser_checks_1.c split_utils.c fill_adjacent_list.c \
			list_sort.c initialize_params.c free_params.c \
			print_general_details.c fill_adjacent_list_2.c \
			list_utils.c parse_fatal_errors_check.c \
			check_start_connected_to_end.c \
			ft_lstnew_revisited.c list_utils_2.c \

SRC = $(addprefix $(SRC_DIR)/, $(SRC_RAW))

OBJ = $(addprefix $(OBJ_DIR)/, $(subst .c,.o,$(SRC_RAW)))

HEADERS = lem-in.h

CCC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFT_DIR)

GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"

all:
		@(cd $(LIBFT_DIR) && $(MAKE))
		@mkdir -p $(OBJ_DIR)
		@make $(BIN_DIR)/$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) $(MAKEFILE)
		@$(CCC) -c $< -o $@ $(CFLAGS)

$(BIN_DIR)/$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT) 
		@$(CCC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
		@echo ${GREEN}"Compiled $(NAME) with success"${RESET}

clean:
		@rm -f $(OBJ)
		@rm -Rf $(OBJ_DIR)
		@(cd $(LIBFT_DIR) && $(MAKE) $@)
		@echo ${CYAN}"Cleaned $(NAME) objects with success"${RESET}

fclean: clean
		@rm -f $(NAME)
		@(cd $(LIBFT_DIR) && $(MAKE) $@)
		@echo ${CYAN}"Removed $(BIN_DIR)/$(NAME) with success"${RESET}

re: fclean all

.PHONY: clean fclean
