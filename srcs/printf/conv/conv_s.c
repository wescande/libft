/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:02:15 by wescande          #+#    #+#             */
/*   Updated: 2017/04/08 00:12:55 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_printf_wstracc(t_conv *tmp, short int acc, wchar_t *wstr)
{
	char		*ret;
	char		*dest;
	short int	i;
	short int	len;

	len = 0;
	i = 0;
	while (len + ft_charwlen(wstr[i]) <= acc)
	{
		len += ft_charwlen(wstr[i]);
		++i;
	}
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tmp->len = len;
	i = 0;
	dest = ret;
	while (len - ft_charwlen(wstr[i]) >= 0)
	{
		ret = ft_charwtochar(ret, wstr[i]) + ft_charwlen(wstr[i]);
		len -= ft_charwlen(wstr[i]);
		++i;
	}
	*ret = '\0';
	return (dest);
}

void			conv_b_s(t_wrk *w, t_conv *tmp, va_list ap)
{
	wchar_t		*wstr;
	char		*str;

	(void)w;
	wstr = CASTVA_ARG(ap, wchar_t *);
	if (tmp->acc == -1 || !wstr)
		str = ft_strwtonewstr(wstr);
	else
	{
		str = ft_printf_wstracc(tmp, tmp->acc, wstr);
		tmp->acc = -1;
	}
	if (!str)
		add_s(tmp, ft_strdup("(null)"));
	else
		add_s(tmp, str);
}

void			conv_s(t_wrk *w, t_conv *tmp, va_list ap)
{
	char	*str;

	if (tmp->is_long)
		return (conv_b_s(w, tmp, ap));
	str = CASTVA_ARG(ap, char *);
	if (!str)
		add_s(tmp, ft_strdup("(null)"));
	else
		add_s(tmp, ft_strdup(str));
}

void			conv_unknow(t_wrk *w, t_conv *tmp, va_list ap)
{
	(void)w;
	(void)ap;
	tmp->acc = -1;
	add_s(tmp, tmp->str);
}
