#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/29 21:32:58 by wescande          #+#    #+#             *#
#*   Updated: 2016/09/27 20:14:55 by wescande         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/
INC_DIR = includes/
OBJ_DIR = objs/

SRC_BASE = convert/ft_atoi.c\
		   convert/ft_itoa.c\
		   lst/ft_lstadd.c\
		   lst/ft_lstdel.c\
		   lst/ft_lstdelone.c\
		   lst/ft_lstiter.c\
		   lst/ft_lstmap.c\
		   lst/ft_lstnew.c\
		   mem/ft_bzero.c\
		   mem/ft_memalloc.c\
		   mem/ft_memccpy.c\
		   mem/ft_memchr.c\
		   mem/ft_memcmp.c\
		   mem/ft_memcpy.c\
		   mem/ft_memdel.c\
		   mem/ft_memmove.c\
		   mem/ft_memrealloc.c\
		   mem/ft_memset.c\
		   put/ft_putchar.c\
		   put/ft_putchar_fd.c\
		   put/ft_putendl.c\
		   put/ft_putendl_fd.c\
		   put/ft_putnbr.c\
		   put/ft_putnbr_fd.c\
		   put/ft_putstr.c\
		   put/ft_putstr_fd.c\
		   str/ft_isalnum.c\
		   str/ft_isalpha.c\
		   str/ft_isascii.c\
		   str/ft_isdigit.c\
		   str/ft_isprint.c\
		   str/ft_strcat.c\
		   str/ft_strchr.c\
		   str/ft_strclr.c\
		   str/ft_strcmp.c\
		   str/ft_strcpy.c\
		   str/ft_strdel.c\
		   str/ft_strdup.c\
		   str/ft_strequ.c\
		   str/ft_striter.c\
		   str/ft_striteri.c\
		   str/ft_strjoin.c\
		   str/ft_strjoinf.c\
		   str/ft_strlcat.c\
		   str/ft_strlen.c\
		   str/ft_strmap.c\
		   str/ft_strmapi.c\
		   str/ft_strncat.c\
		   str/ft_strncmp.c\
		   str/ft_strncpy.c\
		   str/ft_strnequ.c\
		   str/ft_strnew.c\
		   str/ft_strnstr.c\
		   str/ft_strrchr.c\
		   str/ft_strsplit.c\
		   str/ft_strstr.c\
		   str/ft_strsub.c\
		   str/ft_strtrim.c\
		   str/ft_tolower.c\
		   str/ft_toupper.c\
		   int/ft_int_len.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all :
	@$(MAKE) -j $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	@echo "\rCreating $(NAME). . ."
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\r$(NAME) is done."

$(OBJ_DIR) :
	@echo "Create directory"
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "Compile $< to $@ . . ."
	@$(CC) $(FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)

clean :
	@echo "\rclean $(NAME)."
	@rm -rf $(OBJ_DIR)

fclean : clean
	@echo "\rfclean $(NAME)."
	@rm -rf $(NAME)

re : fclean all

.PHONY : fclean clean re

-include $(OBJS:.o=.d)
