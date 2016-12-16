/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:41:17 by wescande          #+#    #+#             */
/*   Updated: 2016/12/16 14:52:31 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			checkmodify(t_conv *tmp, char **end)
{
	if (**end == 'h' && *(1 + *end) == 'h')
	{
		++(*end);
		return ((tmp->is_char = true));
	}
	if (**end == 'h')
		return ((tmp->is_short = true));
	if (**end == 'l' && *(1 + *end) == 'l')
	{
		++(*end);
		return ((tmp->is_long_long = true));
	}
	if (**end == 'l')
		return ((tmp->is_long = true));
	if (**end == 'j' || **end == 'z')
	{
		tmp->is_long_long = false;
		return ((tmp->is_long = true));
	}
	if (**end == 'L')
		return ((tmp->is_long_long = true));
	return (false);
}

static int			checkaccuracy(t_wrk *w, t_conv *tmp, char **end)
{
	if (**end == '.')
	{
		++(*end);
		if (**end == '*')
		{
			tmp->acc = CASTVA_ARG(w->ap, int);
			if (tmp->acc < -1)
				tmp->acc = -1;
			return (true);
		}
		if (ft_isdigit(**end))
		{
			tmp->acc = ft_atoi(*end);
			*end += ft_num_len_base(tmp->acc, 10) - 1;
			return (true);
		}
		--(*end);
		tmp->acc = 0;
		return (true);
	}
	return (checkmodify(tmp, end));
}

static int			checkflag_and_modify(t_wrk *w, t_conv *tmp, char **end)
{
	if (!**end)
		return (false);
	if (**end == '-')
	{
		tmp->pad = ' ';
		return ((tmp->left = true));
	}
	if (**end == '+')
		return ((tmp->sign = true));
	if (**end == ' ')
		return ((tmp->spa = true));
	if (**end == '#')
		return ((tmp->sha = true));
	if (**end == '*')
		return ((tmp->width = CASTVA_ARG(w->ap, int)) ? true : true);
	if (**end == '0')
		return (!tmp->left ? tmp->pad = '0' : true);
	if (ft_isdigit(**end))
	{
		tmp->width = ft_atoi(*end);
		*end += ft_num_len_base(tmp->width, 10) - 1;
		return (true);
	}
	return (checkaccuracy(w, tmp, end));
}

static void			ini_conv(t_conv *c)
{
	c->index_conv = -1;
	c->is_neg = false;
	c->num = 0;
	c->dbl = 0;
	c->len = 0;
	c->base = 10;
	c->sha = false;
	c->spa = false;
	c->left = false;
	c->sign = false;
	c->is_long_long = false;
	c->is_long = false;
	c->is_short = false;
	c->is_char = false;
	c->width = 0;
	c->acc = -1;
	c->pad = ' ';
	c->spec = '\0';
}

void				ft_set_flag(t_wrk *w, t_conv *tmp, char **end)
{
	static char	*flag = "sSpdDioOuUxXcCbBeEfFgGaAn";
	short int	i;

	ini_conv(tmp);
	while (checkflag_and_modify(w, tmp, end))
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
		tmp->left = true;
		tmp->width = -1 * tmp->width;
	}
}
