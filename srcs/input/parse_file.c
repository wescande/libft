/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:45:17 by wescande          #+#    #+#             */
/*   Updated: 2018/07/06 15:04:18 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

int		parse_file(char *filename, t_parse_callback f, void *context)
{
	int		fd;
	char	*line;
	int		ret;

	if (-1 == (fd = open(filename, O_RDONLY)))
		return (ERR_SET(-1, E_OPEN, filename, strerror(errno)));
	ret = 0;
	while (!ret && 0 >= (ret = get_next_line(fd, &line)))
	{
		ret = f(line, context);
		free(line);
	}
	close(fd);
	return (ret);
}
