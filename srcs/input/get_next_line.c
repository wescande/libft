/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:26:24 by wescande          #+#    #+#             */
/*   Updated: 2018/07/06 14:57:37 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			*memjoin_free_1(void *m1, size_t l1, void *m2, size_t l2)
{
	void	*ret;

	if (!(ret = malloc(l1 + l2 + 1)))
		return (NULL);
	if (m1)
	{
		ft_memcpy(ret, m1, l1);
		free(m1);
	}
	ft_memcpy(ret + l1, m2, l2);
	return (ret);
}

static t_buf		*get_buffer(t_lx *head, int fd, char **line)
{
	t_buf	*entry;

	LIST_FOR_EACH_ENTRY_0(entry, head, lx_buffer);
	while (LIST_FOR_EACH_ENTRY_1(entry, head, lx_buffer))
	{
		if (fd == entry->fd)
		{
			if (!line)
			{
				list_del_init(&entry->lx_buffer);
				free(entry);
				return (NULL);
			}
			return (entry);
		}
	}
	if (!line)
		return (NULL);
	if (!(entry = (t_buf *)malloc(sizeof(t_buf))))
		return (NULL);
	ft_bzero(entry, sizeof(t_buf));
	entry->fd = fd;
	list_add(&entry->lx_buffer, head);
	return (entry);
}

static int			__get_next_line_internal(t_buf *ref, char **line, int *len)
{
	char	*eo_line;
	char	*b;

	if (ref->end > ref->start)
	{
		b = ref->c + ref->start;
		if ((eo_line = ft_memchr(b, '\n', ref->end - ref->start)))
		{
			if (!(*line = memjoin_free_1(*line, *len, b, eo_line - b + 1)))
				return (GNL_ERROR);
			*len += eo_line - b;
			ref->start = eo_line - ref->c + 1;
			return (NEWLINE_FOUND);
		}
		if (!(*line = memjoin_free_1(*line, *len, b, ref->end - ref->start)))
			return (GNL_ERROR);
		*len += ref->end - ref->start;
	}
	ref->start = 0;
	if (-1 == (ref->end = read(ref->fd, ref->c, BUFF_SIZE)))
		return (GNL_ERROR);
	return (ref->end > 0 ? NO_END : READ_EOF);
}

int				get_next_line(const int fd, char **line)
{
	static t_lx		head = LIST_HEAD_INIT(head);
	t_buf			*buffer;
	int				len;
	int				ret;

	if (!(buffer = get_buffer(&head, fd, line)))
		return (GNL_ERROR);
	*line = NULL;
	len = 0;
	ret = NO_END;
	while (ret == NO_END)
	{
		ret = __get_next_line_internal(buffer, line, &len);
		if (ret == NO_END || (ret == READ_EOF && !*line) || ret == GNL_ERROR)
			continue ;
		(*line)[len] = '\0';
		return (NEWLINE_FOUND);
	}
	free(*line);
	*line = NULL;
	list_del_init(&buffer->lx_buffer);
	free(buffer);
	return (ret);
}
