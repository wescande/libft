/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 00:24:16 by wescande          #+#    #+#             */
/*   Updated: 2017/10/20 12:09:37 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_buf(t_wrk *w, char **in, int len)
{
	char	*tmp;

	if (len + w->len > w->curlen)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (w->curlen + len + 2048))))
			exit(1);
		if (w->curlen)
		{
			ft_memcpy(tmp, w->ans, w->curlen);
			ft_strdel(&w->ans);
		}
		else
			tmp[0] = '\0';
		w->ans = tmp;
		w->curlen += len + 2048;
	}
	ft_memcpy(w->ans + w->len, *in, len);
}

void				printf_core(t_wrk *w, va_list ap)
{
	char	*end;
	t_conv	tmp;

	while ((end = ft_strchr(w->buf, '%')))
	{
		tmp.len = end - w->buf;
		add_buf(w, &w->buf, tmp.len);
		w->len += tmp.len;
		++end;
		ft_set_flag(&tmp, &end, ap);
		if (tmp.index_conv >= 0)
			(w->fun[tmp.index_conv])(w, &tmp, ap);
		w->buf = end;
		add_buf(w, &(tmp.str), tmp.len);
		ft_strdel(&tmp.str);
		w->len += tmp.len;
	}
	tmp.len = ft_strlen(w->buf);
	add_buf(w, &(w->buf), tmp.len + 1);
	w->len += tmp.len;
}
