# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 10:57:34 by mcoskune          #+#    #+#              #
#    Updated: 2024/12/12 11:47:08 by mcoskune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	muk_lib
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3 -O3
AR		=	ar -rcs

SRC		=	./Convert/deg_to_rad.c \
			./Convert/ft_atod.c \
			./Convert/rad_to_deg.c \
			./Files/check_extension.c \
			./Files/check_access.c \
			./Maths/check_range.c \
			./Memory/add_to_dptr.c \
			./Memory/safe_malloc.c \
			./Memory/ft_bzero.c \
			./Memory/free_dptr.c \
			./Print/errmsg.c \
			./Print/print_dptr_debug.c \
			./String/ft_isalnum.c \
			./String/ft_isalpha.c \
			./String/ft_isdigit.c \
			./String/ft_split.c \
			./String/ft_strlen.c \
			./String/ft_strval.c \

OBJ_DIR	=	objects
OBJ		=	$(patsubst ./%.c, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o: ./%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@$(AR) $(NAME) $^

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
