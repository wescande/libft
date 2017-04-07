/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:26:18 by wescande          #+#    #+#             */
/*   Updated: 2017/04/08 00:12:19 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_double(t_conv *tmp, va_list ap)
{
	if (tmp->is_long)
		tmp->dbl = CASTVA_ARG(ap, long double);
	else
		tmp->dbl = CASTVA_ARG(ap, double);
	if (tmp->dbl < 0)
	{
		tmp->dbl = -1 * tmp->dbl;
		tmp->is_neg = 1;
	}
	add_f(tmp);
}

void			conv_b_f(t_wrk *w, t_conv *tmp, va_list ap)
{
	(void)w;
	tmp->spec = 'F';
	set_double(tmp, ap);
}

void			conv_f(t_wrk *w, t_conv *tmp, va_list ap)
{
	(void)w;
	tmp->spec = 'f';
	set_double(tmp, ap);
}
