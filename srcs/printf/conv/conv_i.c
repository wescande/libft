/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:37:06 by wescande          #+#    #+#             */
/*   Updated: 2016/11/22 12:53:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_b_d(t_wrk *w, t_conv *tmp)
{
	long long int	recup;

	recup = CASTVA_ARG(w->ap, long int);
	if (recup < 0)
	{
		tmp->is_neg = true;
		tmp->num = recup * -1;
	}
	else
		tmp->num = recup;
	add_i(tmp);
}

void	conv_i(t_wrk *w, t_conv *tmp)
{
	long long int	recup;

	if (tmp->is_long_long)
		recup = CASTVA_ARG(w->ap, long long int);
	else if (tmp->is_long)
		recup = CASTVA_ARG(w->ap, long int);
	else if (tmp->is_char)
		recup = (char)CASTVA_ARG(w->ap, int);
	else if (tmp->is_short)
		recup = (short int)CASTVA_ARG(w->ap, int);
	else
		recup = CASTVA_ARG(w->ap, int);
	if (recup < 0)
	{
		tmp->is_neg = true;
		tmp->num = recup * -1;
	}
	else
		tmp->num = recup;
	add_i(tmp);
}
