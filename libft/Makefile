# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 15:49:32 by jmoucach          #+#    #+#              #
#    Updated: 2019/11/11 10:49:41 by jmoucach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC= gcc
# CFLAGS= -Wall -Werror -Wextra
# FILE= ./ft_putchar.c\
# 	 ./ft_putchar_fd.c\
# 	 ./ft_putnbr.c\
# 	 ./ft_putnbr_fd.c\
# 	 ./ft_putstr.c\
# 	 ./ft_putstr_fd.c\
# 	 ./ft_putendl.c\
# 	 ./ft_putendl_fd.c\
# 	 ./ft_strlen.c\
# 	 ./ft_isalpha.c\
# 	 ./ft_isdigit.c\
# 	 ./ft_isalnum.c\
# 	 ./ft_isascii.c\
# 	 ./ft_isprint.c\
# 	 ./ft_toupper.c\
# 	 ./ft_tolower.c\
# 	 ./ft_strcmp.c\
# 	 ./ft_strncmp.c\
# 	 ./ft_strcpy.c\
# 	 ./ft_strncpy.c\
# 	 ./ft_strdup.c\
# 	 ./ft_strcat.c\
# 	 ./ft_strncat.c\
# 	 ./ft_strlcat.c\
# 	 ./ft_atoi.c\
# 	 ./ft_itoa.c\
# 	 ./ft_strstr.c\
# 	 ./ft_strnstr.c\
# 	 ./ft_strchr.c\
# 	 ./ft_strrchr.c\
# 	 ./ft_strequ.c\
# 	 ./ft_strnequ.c\
# 	 ./ft_strclr.c\
# 	 ./ft_striter.c\
# 	 ./ft_striteri.c\
# 	 ./ft_strmap.c\
# 	 ./ft_strmapi.c\
# 	 ./ft_strnew.c\
# 	 ./ft_strdel.c\
# 	 ./ft_strsub.c\
# 	 ./ft_strjoin.c\
# 	 ./ft_strtrim.c\
# 	 ./ft_strsplit.c\
# 	 ./ft_memset.c\
# 	 ./ft_memalloc.c\
# 	 ./ft_memdel.c\
# 	 ./ft_memcpy.c\
# 	 ./ft_memccpy.c\
# 	 ./ft_memcmp.c\
# 	 ./ft_memmove.c\
# 	 ./ft_memchr.c\
# 	 ./ft_bzero.c\
# 	 ./ft_lstnew.c\
# 	 ./ft_lstdelone.c\
# 	 ./ft_lstdel.c\
# 	 ./ft_lstadd.c\
# 	 ./ft_lstiter.c\
# 	 ./ft_lstmap.c\
# 	 ./ft_strrev.c\
# 	 ./get_next_line.c\
# 	 ./ft_sqrt.c\
# 	 ./ft_replace.c\
# 	 ./ft_strtrimc.c\
# 	 ./ft_strlen_chr.c
# OBJ= $(FILE:.c=.o)
# NAME= libft.a

# all: $(NAME)

# $(NAME): $(OBJ)
# 	ar rc $(NAME) $(OBJ)
# 	ranlib $(NAME)


# %.o: %.c
# 	$(CC) -o $@ -c $< $(CFLAGS)

# clean:
# 	rm -rf $(OBJ)

# fclean: clean
# 	rm -rf $(NAME)

# re: fclean all

# .PHONY: all clean fclean re




################################################################################
#								Colors										   #
################################################################################

RED= \033[31m
WHITE= \033[0m
GREEN= \033[32m
CYAN= \033[36m
BLUE= \033[34m
YELLOW= \033[33m
MAGENTA= \033[35m

################################################################################
#								Macros										   #
################################################################################
NAME= libft.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror -g -I/Users/jmoucach/.brew/include/SDL2
SRC_DIR= src/
SRC= ./ft_putchar.c\
	 ./ft_putchar_fd.c\
	 ./ft_putnbr.c\
	 ./ft_putnbr_fd.c\
	 ./ft_putstr.c\
	 ./ft_putstr_fd.c\
	 ./ft_putendl.c\
	 ./ft_putendl_fd.c\
	 ./ft_strlen.c\
	 ./ft_isalpha.c\
	 ./ft_isdigit.c\
	 ./ft_isalnum.c\
	 ./ft_isascii.c\
	 ./ft_isprint.c\
	 ./ft_toupper.c\
	 ./ft_tolower.c\
	 ./ft_strcmp.c\
	 ./ft_strncmp.c\
	 ./ft_strcpy.c\
	 ./ft_strncpy.c\
	 ./ft_strdup.c\
	 ./ft_strcat.c\
	 ./ft_strncat.c\
	 ./ft_strlcat.c\
	 ./ft_atoi.c\
	 ./ft_itoa.c\
	 ./ft_strstr.c\
	 ./ft_strnstr.c\
	 ./ft_strchr.c\
	 ./ft_strrchr.c\
	 ./ft_strequ.c\
	 ./ft_strnequ.c\
	 ./ft_strclr.c\
	 ./ft_striter.c\
	 ./ft_striteri.c\
	 ./ft_strmap.c\
	 ./ft_strmapi.c\
	 ./ft_strnew.c\
	 ./ft_strdel.c\
	 ./ft_strsub.c\
	 ./ft_strjoin.c\
	 ./ft_strtrim.c\
	 ./ft_strsplit.c\
	 ./ft_memset.c\
	 ./ft_memalloc.c\
	 ./ft_memdel.c\
	 ./ft_memcpy.c\
	 ./ft_memccpy.c\
	 ./ft_memcmp.c\
	 ./ft_memmove.c\
	 ./ft_memchr.c\
	 ./ft_bzero.c\
	 ./ft_lstnew.c\
	 ./ft_lstdelone.c\
	 ./ft_lstdel.c\
	 ./ft_lstadd.c\
	 ./ft_lstiter.c\
	 ./ft_lstmap.c\
	 ./ft_strrev.c\
	 ./get_next_line.c\
	 ./ft_sqrt.c\
	 ./ft_replace.c\
	 ./ft_strtrimc.c\
	 ./ft_strlen_chr.c\
	 ./ft_abs.c
SRCS= $(addprefix $(SRC_DIR),$(SRC))
OBJ_DIR= obj/
OBJ= $(SRC:.c=.o)
OBJS= $(addprefix $(OBJ_DIR), $(OBJ))
INCLUDES=	libft.h
###############################################################################
#								Rules										  #
###############################################################################

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	@ echo "$(YELLOW)Creating $@ executable$(WHITE)"
	@ ar rc $(NAME) $(OBJS)
	@ ranlib $(NAME)
	@echo "$(GREEN)$@ executable created$(WHITE)"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(INCLUDES) Makefile
	@ $(CC) -o $@ -c $< $(CFLAGS)
	@ echo "$(GREEN)[✔]$(WHITE)$@"

clean:
	@ echo "$(YELLOW)Deleting objectps$(WHITE)"
	@ for i in $(OBJ); do \
		echo "$(RED)- Deleting $$i$(WHITE)"; \
	done;
	@ echo "$(GREEN)Objects deleted$(WHITE)"
	@ rm -rf $(OBJS)

fclean: clean
	@ echo "$(YELLOW)Deleting obj directory$(WHITE)"
	@ rm -rf obj
	@ echo "$(GREEN)Obj directory deleted$(WHITE)"
	@ echo "$(GREEN)Executable deleted$(WHITE)"
	@ rm -rf $(NAME)

re: fclean all

FORCE:

.PHONY: all re fclean clean