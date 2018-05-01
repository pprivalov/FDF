# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/26 00:44:23 by pprivalo          #+#    #+#              #
#    Updated: 2018/02/14 12:21:07 by pprivalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

SRC_DIR := ./
OBJ_DIR := ./obj/
INC_DIR := ./inc/
LIB_DIR := ./lib/

SRC := main.c ft_map_reader.c ft_errors.c ft_hooks.c ft_drawer.c ft_transform.c \
		ft_vectors.c ft_color.c ft_draw_help.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR := $(LIB_DIR)libft
LIBFT_INC := $(LIBFT_DIR)
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)

CC_FLAGS := -Wall -Wextra -Werror

LINK_FLAGS := $(LIBFT_FLAGS)

HEADER_FLAGS := -I $(INC_DIR) -I $(LIBFT_INC)

CC := gcc

all: $(NAME)
	@echo -ne "\r\r\033[0;32mDone!\033[0m\r"

$(NAME): $(LIBFT) $(OBJ)
	@echo -ne "\r\r\033[0;33mCompiling fdf...\033[0m\r"
	@$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME) $(LIB_DIR)libmlx/libmlx.a -framework OpenGL -framework AppKit

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@echo -ne "\r\r\033[0;33mCompiling libft...\033[0m\r"
	@make -C $(LIBFT_DIR)

clean:
	@echo -ne "\r\033[0;31mClean objects...\033[0m\r"
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re