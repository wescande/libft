/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_adding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:52:25 by wescande          #+#    #+#             */
/*   Updated: 2016/12/06 22:58:47 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*create_suffixe(short int pow, char cmp)
{
	char	*suffixe;

	if (pow < 0)
	{
		pow = -1 * pow;
		suffixe = ft_strjoin(cmp == 'f' ? "e" : "E", "-");
	}
	else
		suffixe = ft_strjoin(cmp == 'f' ? "e" : "E", "+");
	if (pow > 10)
		suffixe = ft_strjoinf(suffixe, ft_itoa(pow), 3);
	else
	{
		suffixe = ft_strjoinf(suffixe, "0", 1);
		suffixe = ft_strjoinf(suffixe, ft_itoa(pow), 3);
	}
	return (suffixe);
}

void			add_e(t_conv *tmp)
{
	short int	len;
	short int	pow;

	pow = 0;
	while (tmp->dbl >= 10.0 && ++pow)
		tmp->dbl /= 10;
	while (tmp->dbl < 1.0 && --pow)
		tmp->dbl *= 10;
	tmp->str = ft_ftoa(tmp->dbl, tmp->acc);
	len = ft_strlen(tmp->str);
	tmp->acc = 0;
	tmp->width -= 4;
	fill_numbers(tmp, len);
	tmp->str = ft_strjoinf(tmp->str, create_suffixe(pow, tmp->spec), 3);
	tmp->len = ft_strlen(tmp->str);
}

void			add_f(t_conv *tmp)
{
	short int	len;

	tmp->str = ft_ftoa(tmp->dbl, tmp->acc);
	len = ft_strlen(tmp->str);
	tmp->acc = 0;
	fill_numbers(tmp, len);
	tmp->len = ft_strlen(tmp->str);
}

void			add_i(t_conv *tmp)
{
	short int		len;

	if (tmp->acc < 0)
		tmp->acc = tmp->base == 8 && !tmp->num ? tmp->acc : 1;
	else
		tmp->pad = ' ';
	if (!tmp->acc && !tmp->num)
		tmp->str = ft_strnewc(1, 0);
	else
		tmp->str = ft_ulitoa_base(tmp->num, tmp->base, tmp->spec == 'X');
	len = ft_strlen(tmp->str);
	if (tmp->acc != -1)
		tmp->acc = tmp->acc < len ? 0 : tmp->acc - len;
	fill_numbers(tmp, len);
	tmp->len = ft_strlen(tmp->str);
}

void			add_s(t_conv *tmp, char *in)
{
	int		len;

	len = tmp->len ? tmp->len : (int)ft_strlen(in);
	if (tmp->acc != -1 && len > tmp->acc)
	{
		in = ft_strsubf(in, 0, tmp->acc, 1);
		len = tmp->acc;
	}
	fill_c(&in, tmp, tmp->width - len);
	tmp->len = len > tmp->width ? len : tmp->width;
	tmp->str = in;
}
