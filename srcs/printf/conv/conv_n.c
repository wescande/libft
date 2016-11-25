/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:31:07 by wescande          #+#    #+#             */
/*   Updated: 2016/11/23 17:31:11 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			conv_n(t_wrk *w, t_conv *tmp)
{
	int		*val;

	(void)tmp;
	val = CASTVA_ARG(w->ap, int *);
	*val = w->len;
	tmp->str = ft_strnew(0);
	tmp->len = 0;
}
