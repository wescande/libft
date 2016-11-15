/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:21:02 by wescande          #+#    #+#             */
/*   Updated: 2016/11/15 16:02:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 1024
# endif

typedef struct		s_buf
{
	char			txt[BUFF_SIZE + 1];
	int				fd;
	int				pos;
	int				read_ret;
	int				newline;
}					t_buf;


#endif
