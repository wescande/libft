/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:21:02 by wescande          #+#    #+#             */
/*   Updated: 2018/07/06 12:52:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>

# define GNL_ERROR		-1
# define READ_EOF		0
# define NEWLINE_FOUND	1
# define NO_END			2

# ifndef BUFF_SIZE
#  define BUFF_SIZE 1024
# endif

typedef struct
{
	t_lx			lx_buffer;
	int				fd;
	int				start;
	int				end;
	char			c[BUFF_SIZE];
}					t_buf;

int				get_next_line(const int fd, char **line);

#endif
