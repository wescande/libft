/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:10:09 by wescande          #+#    #+#             */
/*   Updated: 2017/04/08 00:24:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vasprintf(char **ret, const char *str, va_list ap)
{
	t_wrk	w;
	int		len;

	if (!str)
		return (0);
	initialize_work(str, &w);
	printf_core(&w, ap);
	w.buf = w.ans;
	ft_colorize(&w);
	*ret = w.ans;
	len = w.len;
	return (len);
}

int					ft_vdprintf(int fd, const char *str, va_list ap)
{
	char	*ret;
	int		len;

	ret = NULL;
	if ((len = ft_vasprintf(&ret, str, ap)) != -1)
		ft_putstr_fd(ret, fd);
	ft_strdel(&ret);
	return (len);
}

int					ft_printf(const char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	return (ft_vdprintf(1, str, ap));
}

int					ft_asprintf(char **ret, const char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	return (ft_vasprintf(ret, str, ap));
}

int					ft_dprintf(int fd, const char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	return (ft_vdprintf(fd, str, ap));
}
