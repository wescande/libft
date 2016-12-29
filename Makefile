#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/29 21:32:58 by wescande          #+#    #+#             *#
#*   Updated: 2016/12/24 02:14:21 by wescande         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME		=	libft.a

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -O3

LEN_NAME	=	`printf "%s" $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-24-$(LEN_NAME)"|bc)

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	= \
get_next_line.c\
ld/ft_ld_back.c\
ld/ft_ld_clear.c\
ld/ft_ld_del.c\
ld/ft_ld_front.c\
ld/ft_ld_new.c\
ld/ft_ld_pushback.c\
ld/ft_ld_pushfront.c\
ld/ft_ld_reverse.c\
ld/ft_ld_size.c\
ld/ft_ld_swap.c\
lst/ft_lstadd.c\
lst/ft_lstdel.c\
lst/ft_lstdelone.c\
lst/ft_lstfree.c\
lst/ft_lstiter.c\
lst/ft_lstmap.c\
lst/ft_lstnew.c\
lst/ft_lstreverse.c\
lst/ft_lstsize.c\
lst/ft_lstsort.c\
lst/ft_lstswap.c\
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
wchar/ft_charwlen.c\
wchar/ft_charwtochar.c\
wchar/ft_charwtonewchar.c\
wchar/ft_strwlen.c\
wchar/ft_strwtonewstr.c\
wchar/ft_strwtostr.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all :
	@$(MAKE) -j $(NAME)

$(NAME) :		$(OBJ_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\r\033[48;5;15;38;5;25m✅ MAKE $(NAME)\033[0m\033[K"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)
	@printf "\r\033[38;5;11m⌛ MAKE %s     plz wait :  %*s\033[0m\033[K" $(NAME) $(DELTA) "$@"

clean :
	@rm -rf $(OBJ_DIR)
	@echo "\r\033[38;5;202m✖ clean $(NAME).\033[0m\033[K"

fclean :		clean
	@rm -rf $(NAME)
	@echo "\r\033[38;5;196m❌ fclean $(NAME).\033[0m\033[K"

re :			fclean all

.PHONY :		fclean clean re

-include $(OBJS:.o=.d)
