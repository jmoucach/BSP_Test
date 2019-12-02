# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 14:38:52 by acostaz           #+#    #+#              #
#    Updated: 2019/12/02 14:26:14 by jmoucach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Wextra -Werror -MMD `sdl2-config --cflags` 

NAME = doom-nukem

LIBFT = libft/libft.a

SRC_NAME= init/main.c\
	 init/init.c\
	 draw/drawline.c\
	 draw/draw_rect_to_sdl.c\
	 draw/draw_minimap.c\
	 draw/show_player.c\
	 draw/draw_2dwall.c\
	 map/new_map.c\
	 map/fill_map.c\
	 map/parsing.c\
	 png/check_png_signature.c \
	 png/idat_block_extraction.c \
	 png/idat_utils.c \
	 png/parse_png.c \
	 png/png_utils.c \
	 png/png_utils2.c \
	 png/post_processing.c \
	 png/process_ihdr.c \
	 png/process_idat.c \
	 png/unfiltering.c \
	 png/unfiltering_utils.c \
	 png/zlib.c \
	 raycasting/raycasting.c\
	 raycasting/floorcaster.c\
	 game/event_loop.c\
	 game/movement.c\
	 image/load_image.c\
	 vertex/dot_product.c\
	 vertex/vertex_basics.c\
	 BSP/classify.c\
	 BSP/new_wlist.c\
	 BSP/IO_wlist.c

SRC_DIR = src
BUILD_DIR = obj
INC_DIR = hdr
OBJ_SUBDIRS= init draw map raycasting game  image vertex png BSP
SUBDIRS= $(foreach dir, $(OBJ_SUBDIRS), $(BUILD_DIR)/$(dir))

LIB= `sdl2-config --libs` \
	 -L libft -lft

OBJ = $(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.o))
DPD = $(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.d))

all:
	@$(MAKE) all -C libft
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@echo "\033[2K \033[A"
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) $(LIBFT) -lm
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(MLX) $(LIBFT)
	@mkdir -p $(SUBDIRS)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	@rm -rf $(BUILD_DIR)
	@echo "\033[33m[$(NAME)]: OBJ deleted\033[0m"

fclean: clean
	@rm -f $(LIBFT)
	@echo "\033[31m[libft.a]: deleted\033[0m"
	@rm -f $(NAME)
	@echo "\033[31m[$(NAME)]: deleted\033[0m"

re : fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)
