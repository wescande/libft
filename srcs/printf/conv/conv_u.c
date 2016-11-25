/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:57:23 by wescande          #+#    #+#             */
/*   Updated: 2016/11/22 12:53:38 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_b_u(t_wrk *w, t_conv *tmp)
{
	tmp->is_neg = false;
	tmp->sign = false;
	tmp->spa = false;
	tmp->num = CASTVA_ARG(w->ap, unsigned long int);
	add_i(tmp);
}

void	conv_u(t_wrk *w, t_conv *tmp)
{
	tmp->is_neg = false;
	tmp->sign = false;
	tmp->spa = false;
	if (tmp->is_long)
		return (conv_b_u(w, tmp));
	if (tmp->is_long_long)
		tmp->num = CASTVA_ARG(w->ap, unsigned long long int);
	else if (tmp->is_char)
		tmp->num = (unsigned char)CASTVA_ARG(w->ap, unsigned int);
	else if (tmp->is_short)
		tmp->num = (unsigned short int)CASTVA_ARG(w->ap, unsigned int);
	else
		tmp->num = CASTVA_ARG(w->ap, unsigned int);
	add_i(tmp);
}
