/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:00:35 by wescande          #+#    #+#             */
/*   Updated: 2016/12/13 17:37:24 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_double(t_conv *tmp)
{
	short int	pow;
	long double	n_tmp;

	pow = 0;
	n_tmp = tmp->dbl;
	while (n_tmp >= 10.0 && ++pow)
		n_tmp /= 10;
	while (n_tmp < 1.0 && --pow)
		n_tmp *= 10;
	if (pow < 6 && pow <= tmp->acc)
	{
		tmp->acc -= (pow);
		if (tmp->acc < 0)
			tmp->acc = 0;
		add_f(tmp);
		while (tmp->str[tmp->len - 1] == '0')
			tmp->str[--tmp->len] = '\0';
		if (tmp->str[tmp->len - 1] == '.')
			tmp->str[--tmp->len] = '\0';
	}
	else
		add_e(tmp);
}

void			conv_b_g(t_wrk *w, t_conv *tmp)
{
	tmp->spec = 'F';
	if (!tmp->acc)
		tmp->acc = 1;
	if (tmp->acc == -1)
		tmp->acc = 6;
	--tmp->acc;
	if (tmp->is_long)
		tmp->dbl = CASTVA_ARG(w->ap, long double);
	else
		tmp->dbl = CASTVA_ARG(w->ap, double);
	if (tmp->dbl < 0)
	{
		tmp->dbl = -1 * tmp->dbl;
		tmp->is_neg = true;
	}
	set_double(tmp);
}

void			conv_g(t_wrk *w, t_conv *tmp)
{
	tmp->spec = 'f';
	if (!tmp->acc)
		tmp->acc = 1;
	if (tmp->acc == -1)
		tmp->acc = 6;
	--tmp->acc;
	if (tmp->is_long)
		tmp->dbl = CASTVA_ARG(w->ap, long double);
	else
		tmp->dbl = CASTVA_ARG(w->ap, double);
	if (tmp->dbl < 0)
	{
		tmp->dbl = -1 * tmp->dbl;
		tmp->is_neg = true;
	}
	set_double(tmp);
}
