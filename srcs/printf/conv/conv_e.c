/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:26:18 by wescande          #+#    #+#             */
/*   Updated: 2016/11/24 15:44:22 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_double(t_wrk *w, t_conv *tmp)
{
	if (tmp->is_long)
		tmp->dbl = CASTVA_ARG(w->ap, long double);
	else
		tmp->dbl = CASTVA_ARG(w->ap, double);
	if (tmp->dbl < 0)
	{
		tmp->dbl = -1 * tmp->dbl;
		tmp->is_neg = true;
	}
	add_e(tmp);
}

void			conv_b_e(t_wrk *w, t_conv *tmp)
{
	tmp->spec = 'F';
	set_double(w, tmp);
}

void			conv_e(t_wrk *w, t_conv *tmp)
{
	tmp->spec = 'f';
	set_double(w, tmp);
}
