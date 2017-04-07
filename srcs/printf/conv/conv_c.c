/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:06:09 by wescande          #+#    #+#             */
/*   Updated: 2017/04/08 00:11:04 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		put_the_s(t_conv *tmp, char *str)
{
	if (!str)
		add_s(tmp, ft_strdup(""));
	else
		add_s(tmp, str);
}

void			conv_b_c(t_wrk *w, t_conv *tmp, va_list ap)
{
	wchar_t		wstr;
	char		*str;

	(void)w;
	wstr = (wchar_t)CASTVA_ARG(ap, int);
	str = ft_charwtonewchar(wstr);
	tmp->acc = -1;
	if (str[0] == 0)
		++tmp->len;
	put_the_s(tmp, str);
}

void			conv_c(t_wrk *w, t_conv *tmp, va_list ap)
{
	char	*str;
	char	c[2];

	if (!tmp->acc)
		tmp->acc = 1;
	if (tmp->is_long)
		return (conv_b_c(w, tmp, ap));
	c[0] = (char)CASTVA_ARG(ap, int);
	c[1] = '\0';
	if (c[0] == 0)
		tmp->len = 1;
	str = ft_strdup(c);
	put_the_s(tmp, str);
}
