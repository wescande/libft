/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:54:37 by wescande          #+#    #+#             */
/*   Updated: 2017/04/08 00:12:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_p(t_wrk *w, t_conv *tmp, va_list ap)
{
	void	*ptr;

	(void)w;
	ptr = CASTVA_ARG(ap, void *);
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
		tmp->sha = 1;
		tmp->num = (unsigned long int)ptr;
		add_i(tmp);
	}
}
