# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 13:33:54 by croy              #+#    #+#              #
#    Updated: 2023/10/30 18:00:29 by croy             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# --------- GLOBAL VARIABLES ----------
SHELL := bash
.SHELLFLAGS := -eu -o pipefail -c # strict bash mode
# MAKEFLAGS += --warn-undefined-variables # warn about Make variables that don’t exist
MAKEFLAGS += --no-print-directory # don’t print the directory name before executing a recipe
.DELETE_ON_ERROR:


# ------------ FORMATTING -------------
# see https://misc.flogisoft.com/bash/tip_colors_and_formatting
FG_BLACK 			:= \033[30m
FG_RED 				:= \033[31m
FG_GREEN 			:= \033[32m
FG_YELLOW 			:= \033[33m
FG_BLUE 			:= \033[34m
FG_MAGENTA 			:= \033[35m
FG_CYAN 			:= \033[36m
FG_LIGHT_GRAY 		:= \033[37m
FG_DEFAULT 			:= \033[39m
FG_DARK_GRAY 		:= \033[90m
FG_LIGHT_RED 		:= \033[91m
FG_LIGHT_GREEN 		:= \033[92m
FG_LIGHT_YELLOW 	:= \033[93m
FG_LIGHT_BLUE 		:= \033[94m
FG_LIGHT_MAGENTA 	:= \033[95m
FG_LIGHT_CYAN 		:= \033[96m
FG_WHITE 			:= \033[97m
FG_ORANGE 			:= \033[38:5:208m

BG_BLACK 			:= \033[40m
BG_RED 				:= \033[41m
BG_GREEN 			:= \033[42m
BG_YELLOW 			:= \033[43m
BG_BLUE 			:= \033[44m
BG_MAGENTA 			:= \033[45m
BG_CYAN 			:= \033[46m
BG_LIGHT_GRAY 		:= \033[47m
BG_DEFAULT 			:= \033[49m
BG_DARK_GRAY 		:= \033[100m
BG_LIGHT_RED 		:= \033[101m
BG_LIGHT_GREEN 		:= \033[102m
BG_LIGHT_YELLOW 	:= \033[103m
BG_LIGHT_BLUE 		:= \033[104m
BG_LIGHT_MAGENTA 	:= \033[105m
BG_LIGHT_CYAN 		:= \033[106m
BG_WHITE 			:= \033[107m

BOLD		:= \033[1m
DIM			:= \033[2m
ITALIC		:= \033[3m
UNDERLINE	:= \033[4m
STRIKED		:= \033[9m
RESET		:= \033[0m


# ---------- BASIC VARIABLES ----------
CFLAGS := -Wall -Wextra -Werror -Ilibft/header/ -Iheader/ -O2 -g3
AR := ar
ARFLAGS := -rcs
FSANITIZE = -fsanitize=address
RM := rm -rf

LIBFT_DIR := libft/
LIBFT_NAME := $(LIBFT_DIR)libft.a
USER := $(shell whoami)


# --------- PROJECT VARIABLES ---------
NAME := cub3D
HEADER := 	header/cub3d.h \
			header/struct.h \
			header/parsing.h \
			header/exec.h

MLX_DIR := mlx_linux/
MLX_NAME := $(MLX_DIR)libmlx_Linux.a
MLX_FLAGS := -lm -lz -lXext -lX11 -I${MLX_DIR}

SRC_FOLDER := src/
OBJ_DIR := obj/
SRC = $(addprefix $(SRC_FOLDER), $(SRC_MAIN) $(SRC_UTILS) $(SCR_PARSING) $(SCR_EXEC))
OBJ = $(subst $(SRC_FOLDER),$(OBJ_DIR),$(SRC:.c=.o))

DIR_MAIN := $(SRC_FOLDER)
SRC_MAIN := cub3d.c

DIR_UTILS := $(SRC_FOLDER)utils/
SRC_UTILS := utils_error.c utils_free.c \
				exec_free.c \

DIR_PARSING := $(SRC_FOLDER)parsing/
SCR_PARSING := check_islands.c check_map.c parse_file.c parse_map.c \
	parse_properties.c parsing.c

DIR_EXEC := $(SRC_FOLDER)exec/
SCR_EXEC := exec_manager.c \
			\
			close_window.c \
			\
			init_mlx.c \
			init_player.c \
			init_ray.c \
			init_textures.c \
			\
			refresh_window.c \
			draw_minimap.c \
			draw_player_minimap.c \
			draw_walls.c \
			draw_textures.c \
			put_pixel.c \
			\
			raycasting.c \
			rotation.c \
			moves.c \
			ft_dda.c \
			\
			textures_utils.c \

# -------------- RECIPES --------------
all: rsc
	make $(NAME)

$(NAME): $(LIBFT_NAME) $(MLX_NAME) $(OBJ)
	@echo -e "\n$(BOLD)Hello $(FG_ORANGE)$(USER)$(RESET)"
	$(AR) $(ARFLAGS) $(LIBFT_NAME) $(MLX_NAME) $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(LIBFT_NAME) $(MLX_NAME)
	@echo -e "$(BG_LIGHT_GREEN)Compiled:\t$(RESET) $(FG_WHITE)$(UNDERLINE)$(NAME)$(RESET) has been created."

$(OBJ_DIR)%.o : $(DIR_MAIN)%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o : $(DIR_UTILS)%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o : $(DIR_PARSING)%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o : $(DIR_EXEC)%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT_NAME):
	@$(MAKE) -sC $(LIBFT_DIR)

$(MLX_NAME) :
	@$(MAKE) -sC $(MLX_DIR)

rsc:
	@$(MAKE) -sC $(LIBFT_DIR)
	@$(MAKE) -sC $(MLX_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)
	@$(MAKE) $@ -sC $(LIBFT_DIR)
	@$(MAKE) $@ -sC $(MLX_DIR)
	@echo -e "$(FG_RED)Clean:\t\t $(FG_LIGHT_GRAY)$(ITALIC)$(NAME) object files$(RESET) have been deleted"

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) $@ -sC $(LIBFT_DIR)
	@echo -e "$(FG_RED)FClean:\t\t $(FG_LIGHT_GRAY)$(UNDERLINE)$(NAME)$(RESET) has been deleted."

re: fclean
	@$(MAKE) rsc
	@$(MAKE) all

debug: CFLAGS += $(FSANITIZE)
debug: fclean $(NAME)

.PHONY: all rsc clean fclean re debug
