/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:01:13 by wescande          #+#    #+#             */
/*   Updated: 2016/11/25 14:08:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_a(t_conv *tmp)
{
	short int	len;
	short int	pow;
	char		*mystr;

	pow = 0;
	while (tmp->dbl >= 2.0 && ++pow)
		tmp->dbl /= 2;
	while (tmp->dbl < 1.0 && --pow)
		tmp->dbl *= 2;
	tmp->str = ft_ftoa_base(tmp->dbl, tmp->acc, tmp->base, tmp->spec == 'X');
	len = ft_strlen(tmp->str);
	mystr = ft_strnewc(tmp->acc - len + 2, '0');
	tmp->str = ft_strjoinf(tmp->str, mystr, 3);
	tmp->acc = 0;
	tmp->width = tmp->width - 2 - ft_num_len_base(pow, 10);
	fill_numbers(tmp, len);
	if (tmp->spec == 'x')
		mystr = ft_strjoin(pow < 0 ? "p" : "p+", ft_itoa(pow));
	else
		mystr = ft_strjoin(pow < 0 ? "P" : "P+", ft_itoa(pow));
	tmp->str = ft_strjoinf(tmp->str, mystr, 3);
	tmp->len = ft_strlen(tmp->str);
}

static void	set_double(t_wrk *w, t_conv *tmp)
{
	tmp->base = 16;
	tmp->sha = true;
	if (tmp->acc == -1)
		tmp->acc = 13;
	if (tmp->is_long)
		tmp->dbl = CASTVA_ARG(w->ap, long double);
	else
		tmp->dbl = CASTVA_ARG(w->ap, double);
	if (tmp->dbl < 0)
	{
		tmp->dbl = -1 * tmp->dbl;
		tmp->is_neg = true;
	}
	add_a(tmp);
}

void		conv_b_a(t_wrk *w, t_conv *tmp)
{
	tmp->spec = 'X';
	set_double(w, tmp);
}

void		conv_a(t_wrk *w, t_conv *tmp)
{
	tmp->spec = 'x';
	set_double(w, tmp);
}
