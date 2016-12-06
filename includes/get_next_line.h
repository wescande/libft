/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:21:02 by wescande          #+#    #+#             */
/*   Updated: 2016/12/06 23:39:58 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 1024
# endif

typedef struct		s_buf
{
	char			txt[BUFF_SIZE];
	int				fd;
	int				pos;
	int				read_ret;
	int				newline;
	int				ret_len;
}					t_buf;

#endif
