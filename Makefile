# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wescande <wescande@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/29 21:32:58 by wescande          #+#    #+#              #
#    Updated: 2017/10/20 14:22:56 by wescande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			?=	gcc
FLAGS		=	-Wall -Wextra -Werror -O3

LEN_NAME	=	`printf "%s" $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-31-$(LEN_NAME)"|bc)

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	= \
42_retro/ld/ft_ld_back.c\
42_retro/ld/ft_ld_clear.c\
42_retro/ld/ft_ld_del.c\
42_retro/ld/ft_ld_front.c\
42_retro/ld/ft_ld_new.c\
42_retro/ld/ft_ld_pushback.c\
42_retro/ld/ft_ld_pushfront.c\
42_retro/ld/ft_ld_reverse.c\
42_retro/ld/ft_ld_size.c\
42_retro/ld/ft_ld_swap.c\
42_retro/ld/ft_ld_to_tab.c\
42_retro/lst/ft_lstadd.c\
42_retro/lst/ft_lstdel.c\
42_retro/lst/ft_lstdelone.c\
42_retro/lst/ft_lstfree.c\
42_retro/lst/ft_lstiter.c\
42_retro/lst/ft_lstmap.c\
42_retro/lst/ft_lstnew.c\
42_retro/lst/ft_lstreverse.c\
42_retro/lst/ft_lstsize.c\
42_retro/lst/ft_lstsort.c\
42_retro/lst/ft_lstswap.c\
byteswap.c\
cliopts_get.c\
cliopts_getmap.c\
error.c\
get_next_line.c\
list/list_add.c\
list/list_cut_position.c\
list/list_del.c\
list/list_empty.c\
list/list_findat.c\
list/list_is_last.c\
list/list_is_singular.c\
list/list_len.c\
list/list_merge.c\
list/list_move.c\
list/list_replace.c\
list/list_rotate_left.c\
list/list_splice.c\
mem/ft_bzero.c\
mem/ft_memalloc.c\
mem/ft_memccpy.c\
mem/ft_memchr.c\
mem/ft_memcmp.c\
mem/ft_memcpy.c\
mem/ft_memdel.c\
mem/ft_memjoin.c\
mem/ft_memjoinf.c\
mem/ft_memmove.c\
mem/ft_memrealloc.c\
mem/ft_memset.c\
mem/ft_swapptr.c\
num/ft_abs.c\
num/ft_atoi.c\
num/ft_atoli_base.c\
num/ft_ftoa.c\
num/ft_itoa.c\
num/ft_litoa.c\
num/ft_max.c\
num/ft_min.c\
num/ft_num_len_base.c\
num/ft_pow.c\
output/ft_putchar.c\
output/ft_putchar_fd.c\
output/ft_putendl.c\
output/ft_putendl_fd.c\
output/ft_putnbr.c\
output/ft_putnbr_fd.c\
output/ft_putstr.c\
output/ft_putstr_fd.c\
output/ft_tabprint.c\
output/ft_tabprint_fd.c\
printf/add/ft_printf_adding.c\
printf/add/ft_printf_fill.c\
printf/conv/conv_a.c\
printf/conv/conv_base.c\
printf/conv/conv_binaire.c\
printf/conv/conv_c.c\
printf/conv/conv_e.c\
printf/conv/conv_f.c\
printf/conv/conv_g.c\
printf/conv/conv_i.c\
printf/conv/conv_n.c\
printf/conv/conv_p.c\
printf/conv/conv_s.c\
printf/conv/conv_u.c\
printf/ft_colorize.c\
printf/ft_printf.c\
printf/input/ft_init.c\
printf/input/ft_set_flag.c\
printf/printf_core.c\
str/ft_isalnum.c\
str/ft_isalpha.c\
str/ft_isascii.c\
str/ft_isdigit.c\
str/ft_isprint.c\
str/ft_isspa.c\
str/ft_strcat.c\
str/ft_strchr.c\
str/ft_strclr.c\
str/ft_strcmp.c\
str/ft_strcpy.c\
str/ft_strdel.c\
str/ft_strdup.c\
str/ft_strequ.c\
str/ft_strisdigit.c\
str/ft_strisnumeral.c\
str/ft_striter.c\
str/ft_striteri.c\
str/ft_strjoin.c\
str/ft_strjoinf.c\
str/ft_strlcat.c\
str/ft_strlen.c\
str/ft_strlenchr.c\
str/ft_strmap.c\
str/ft_strmapi.c\
str/ft_strncat.c\
str/ft_strnchr.c\
str/ft_strncmp.c\
str/ft_strncpy.c\
str/ft_strnequ.c\
str/ft_strnew.c\
str/ft_strnewc.c\
str/ft_strnstr.c\
str/ft_strrchr.c\
str/ft_strsplit.c\
str/ft_strsplitspa.c\
str/ft_strstr.c\
str/ft_strsub.c\
str/ft_strsubf.c\
str/ft_strtoupper.c\
str/ft_strtrim.c\
str/ft_tabdel.c\
str/ft_tablen.c\
str/ft_tolower.c\
str/ft_toupper.c\
sys/ft_getenv.c\
wchar/ft_charwlen.c\
wchar/ft_charwtochar.c\
wchar/ft_charwtonewchar.c\
wchar/ft_strwlen.c\
wchar/ft_strwtonewstr.c\
wchar/ft_strwtostr.c


SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

SHELL := /bin/bash

all :
	@$(MAKE) -j $(NAME)

$(NAME) :		$(OBJ_DIR) $(OBJS) Makefile
	@ar rcs $(NAME) $(OBJS)
	@printf "\r\033[38;5;117m✓ MAKE $(NAME)\033[0m\033[K\n"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c Makefile | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB) - 1))))
	@$(eval COLOR=$(shell list=(160 196 202 208 215 221 226 227 190 154 118 82 46); index=$$(($(PERCENT) * $${#list[@]} / 100)); echo "$${list[$$index]}"))
	@printf "\r\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[K" $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(CC) $(FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean :
	@if [ -e $(OBJ_DIR) ]; \
	then \
		rm -rf $(OBJ_DIR); \
		printf "\r\033[38;5;202m✗ clean $(NAME).\033[0m\033[K\n"; \
	fi;

fclean :		clean
	@if [ -e $(NAME) ]; \
	then \
		rm -rf $(NAME); \
		printf "\r\033[38;5;196m✗ fclean $(NAME).\033[0m\033[K\n"; \
	fi;

re :			fclean all

.PHONY :		fclean clean re

-include $(OBJS:.o=.d)

unit_test:
	@make -C .unit_test re
	@./.unit_test/unit_test
