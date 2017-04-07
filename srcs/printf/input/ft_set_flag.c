/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:41:17 by wescande          #+#    #+#             */
/*   Updated: 2017/04/08 00:15:06 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			checkmodify(t_conv *tmp, char **end)
{
	if (**end == 'h' && *(1 + *end) == 'h')
	{
		++(*end);
		return ((tmp->is_char = 1));
	}
	if (**end == 'h')
		return ((tmp->is_short = 1));
	if (**end == 'l' && *(1 + *end) == 'l')
	{
		++(*end);
		return ((tmp->is_long_long = 1));
	}
	if (**end == 'l')
		return ((tmp->is_long = 1));
	if (**end == 'j' || **end == 'z')
	{
		tmp->is_long_long = 0;
		return ((tmp->is_long = 1));
	}
	if (**end == 'L')
		return ((tmp->is_long_long = 1));
	return (0);
}

static int			checkaccuracy(t_conv *tmp, char **end, va_list ap)
{
	if (**end == '.')
	{
		++(*end);
		if (**end == '*')
		{
			tmp->acc = CASTVA_ARG(ap, int);
			if (tmp->acc < -1)
				tmp->acc = -1;
			return (1);
		}
		if (ft_isdigit(**end))
		{
			tmp->acc = ft_atoi(*end);
			*end += ft_num_len_base(tmp->acc, 10) - 1;
			return (1);
		}
		--(*end);
		tmp->acc = 0;
		return (1);
	}
	return (checkmodify(tmp, end));
}

static int			checkflag_and_modify(t_conv *tmp, char **end, va_list ap)
{
	if (!**end)
		return (0);
	if (**end == '-')
	{
		tmp->pad = ' ';
		return ((tmp->left = 1));
	}
	if (**end == '+')
		return ((tmp->sign = 1));
	if (**end == ' ')
		return ((tmp->spa = 1));
	if (**end == '#')
		return ((tmp->sha = 1));
	if (**end == '*')
		return ((tmp->width = CASTVA_ARG(ap, int)) ? 1 : 1);
	if (**end == '0')
		return (!tmp->left ? tmp->pad = '0' : 1);
	if (ft_isdigit(**end))
	{
		tmp->width = ft_atoi(*end);
		*end += ft_num_len_base(tmp->width, 10) - 1;
		return (1);
	}
	return (checkaccuracy(tmp, end, ap));
}

static void			ini_conv(t_conv *c)
{
	c->index_conv = -1;
	c->is_neg = 0;
	c->num = 0;
	c->dbl = 0;
	c->len = 0;
	c->base = 10;
	c->sha = 0;
	c->spa = 0;
	c->left = 0;
	c->sign = 0;
	c->is_long_long = 0;
	c->is_long = 0;
	c->is_short = 0;
	c->is_char = 0;
	c->width = 0;
	c->acc = -1;
	c->pad = ' ';
	c->spec = '\0';
}

void				ft_set_flag(t_conv *tmp, char **end, va_list ap)
{
	static char	*flag = "sSpdDioOuUxXcCbBeEfFgGaAn";
	short int	i;

	ini_conv(tmp);
	while (checkflag_and_modify(tmp, end, ap))
		++(*end);
	i = 0;
	while (flag[i] && flag[i] != **end)
		++i;
	tmp->index_conv = i;
	if (i == n_fun)
		tmp->str = ft_strnewc(1, **end);
	if (**end)
		++(*end);
	if (tmp->width < 0)
	{
		tmp->left = 1;
		tmp->width = -1 * tmp->width;
	}
}
