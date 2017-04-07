/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:57:23 by wescande          #+#    #+#             */
/*   Updated: 2017/04/08 00:13:15 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_b_u(t_wrk *w, t_conv *tmp, va_list ap)
{
	(void)w;
	tmp->is_neg = 0;
	tmp->sign = 0;
	tmp->spa = 0;
	tmp->num = CASTVA_ARG(ap, unsigned long int);
	add_i(tmp);
}

void	conv_u(t_wrk *w, t_conv *tmp, va_list ap)
{
	tmp->is_neg = 0;
	tmp->sign = 0;
	tmp->spa = 0;
	if (tmp->is_long)
		return (conv_b_u(w, tmp, ap));
	if (tmp->is_long_long)
		tmp->num = CASTVA_ARG(ap, unsigned long long int);
	else if (tmp->is_char)
		tmp->num = (unsigned char)CASTVA_ARG(ap, unsigned int);
	else if (tmp->is_short)
		tmp->num = (unsigned short int)CASTVA_ARG(ap, unsigned int);
	else
		tmp->num = CASTVA_ARG(ap, unsigned int);
	add_i(tmp);
}
