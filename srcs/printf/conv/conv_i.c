/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:37:06 by wescande          #+#    #+#             */
/*   Updated: 2017/04/08 00:12:08 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_b_d(t_wrk *w, t_conv *tmp, va_list ap)
{
	long long int	recup;

	(void)w;
	recup = CASTVA_ARG(ap, long int);
	if (recup < 0)
	{
		tmp->is_neg = 1;
		tmp->num = recup * -1;
	}
	else
		tmp->num = recup;
	add_i(tmp);
}

void	conv_i(t_wrk *w, t_conv *tmp, va_list ap)
{
	long long int	recup;

	(void)w;
	if (tmp->is_long_long)
		recup = CASTVA_ARG(ap, long long int);
	else if (tmp->is_long)
		recup = CASTVA_ARG(ap, long int);
	else if (tmp->is_char)
		recup = (char)CASTVA_ARG(ap, int);
	else if (tmp->is_short)
		recup = (short int)CASTVA_ARG(ap, int);
	else
		recup = CASTVA_ARG(ap, int);
	if (recup < 0)
	{
		tmp->is_neg = 1;
		tmp->num = recup * -1;
	}
	else
		tmp->num = recup;
	add_i(tmp);
}
