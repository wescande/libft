/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:10:09 by wescande          #+#    #+#             */
/*   Updated: 2016/12/16 14:52:48 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_buf(t_wrk *w, char **in, int len, int erase)
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
	if (erase)
		ft_strdel(in);
}

static void			ft_chraction(t_wrk *w)
{
	char	*end;
	t_conv	tmp;

	while ((end = ft_strchr(w->buf, '%')))
	{
		tmp.len = end - w->buf;
		add_buf(w, &w->buf, tmp.len, false);
		w->len += tmp.len;
		++end;
		ft_set_flag(w, &tmp, &end);
		if (tmp.index_conv >= 0)
			w->fun[tmp.index_conv](w, &tmp);
		w->buf = end;
		add_buf(w, &(tmp.str), tmp.len, true);
		w->len += tmp.len;
	}
	tmp.len = ft_strlen(w->buf);
	add_buf(w, &(w->buf), tmp.len + 1, false);
	w->len += tmp.len;
}

int					ft_asprintf(char **ret, const char *str, ...)
{
	t_wrk		*w;
	int			len;

	if (!str)
		return (0);
	w = initialize_work(str);
	va_start(w->ap, str);
	ft_chraction(w);
	w->buf = w->ans;
	ft_colorize(w);
	va_end(w->ap);
	*ret = w->ans;
	len = w->len;
	ft_memdel((void **)&w);
	return (len);
}

int					ft_dprintf(int fd, const char *str, ...)
{
	t_wrk		*w;
	int			ret;

	if (!str)
		return (0);
	w = initialize_work(str);
	va_start(w->ap, str);
	ft_chraction(w);
	w->buf = w->ans;
	ft_colorize(w);
	va_end(w->ap);
	ret = write(fd, w->ans, w->len);
	ft_strdel(&(w->ans));
	ft_memdel((void **)&w);
	return (ret);
}

int					ft_printf(const char *str, ...)
{
	t_wrk		*w;
	int			ret;

	if (!str)
		return (0);
	w = initialize_work(str);
	va_start(w->ap, str);
	ft_chraction(w);
	w->buf = w->ans;
	ft_colorize(w);
	va_end(w->ap);
	ret = write(1, w->ans, w->len);
	ft_strdel(&(w->ans));
	ft_memdel((void **)&w);
	return (ret);
}
