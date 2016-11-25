/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:54:37 by wescande          #+#    #+#             */
/*   Updated: 2016/11/22 12:53:11 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_p(t_wrk *w, t_conv *tmp)
{
	void	*ptr;

	ptr = CASTVA_ARG(w->ap, void *);
	if (!ptr && !tmp->acc)
	{
		--(tmp->acc);
		tmp->len += 2;
		add_s(tmp, ft_strdup("0x"));
	}
	else
	{
		tmp->base = 16;
		tmp->spec = 'x';
		tmp->sha = true;
		tmp->num = (unsigned long int)ptr;
		add_i(tmp);
	}
}
