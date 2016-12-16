/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:57:12 by wescande          #+#    #+#             */
/*   Updated: 2016/12/16 14:52:08 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fill_c(char **in, t_conv *tmp, short int len)
{
	char *filler;

	if (len > 0)
	{
		filler = ft_strnewc(len, tmp->pad);
		if (tmp->left)
			*in = ft_memjoinf(*in, filler,
					tmp->len ? tmp->len : (int)ft_strlen(*in), len);
		else
			*in = ft_memjoinf(filler, *in, len,
					tmp->len ? tmp->len : (int)ft_strlen(*in));
	}
}

static void		fill_i(char **in, char c, short int len, int on_left)
{
	char *filler;

	if (len > 0)
	{
		filler = ft_strnewc(len, c);
		if (on_left)
			*in = ft_strjoinf(*in, filler, 3);
		else
			*in = ft_strjoinf(filler, *in, 3);
	}
}

static void		manage_based(t_conv *tmp, short int len)
{
	if (tmp->sha && tmp->base == 16)
		tmp->width -= 2;
	else if (tmp->sha && tmp->base == 8)
	{
		tmp->acc -= tmp->acc > len ? 1 : 0;
		--tmp->width;
	}
	if (tmp->acc != -1)
		fill_i(&(tmp->str), '0', tmp->acc, false);
	if (tmp->pad == '0')
		fill_i(&(tmp->str), '0', tmp->width, false);
	if (tmp->sha)
	{
		if (tmp->base == 16)
		{
			fill_i(&(tmp->str), tmp->spec, 1, false);
			fill_i(&(tmp->str), '0', 1, false);
		}
		else if (tmp->base == 8 && (tmp->num || !tmp->acc))
			fill_i(&(tmp->str), '0', 1, false);
	}
	fill_i(&(tmp->str), '-', tmp->is_neg, false);
	if (tmp->pad == ' ')
		fill_i(&(tmp->str), ' ', tmp->width, tmp->left);
}

static void		manage_decimal(t_conv *tmp)
{
	tmp->width -= ((tmp->is_neg && tmp->str[0] != '-')
			|| tmp->sign || tmp->spa);
	fill_i(&(tmp->str), '0', tmp->acc, tmp->spec == 'f' || tmp->spec == 'F');
	if (tmp->pad == '0')
		fill_i(&(tmp->str), '0', tmp->width, false);
	if (tmp->is_neg)
		fill_i(&(tmp->str), '-', 1, false);
	else if (tmp->sign)
		fill_i(&(tmp->str), '+', 1, false);
	else if (tmp->spa)
		fill_i(&(tmp->str), ' ', 1, false);
	if (tmp->pad == ' ')
		fill_i(&(tmp->str), ' ', tmp->width, tmp->left);
}

void			fill_numbers(t_conv *tmp, short int len)
{
	tmp->width -= len + tmp->acc;
	if (tmp->base == 10)
		manage_decimal(tmp);
	else
		manage_based(tmp, len);
}
