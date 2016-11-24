/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:43:26 by wescande          #+#    #+#             */
/*   Updated: 2016/11/24 15:43:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_litoa_under0(long double value, short int prec,
							short int len_base, bool is_up)
{
	static char	*base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	char		*str;
	short int	i;

	if (!(str = (char*)malloc(sizeof(char) * (prec + 1))))
		return (NULL);
	str[prec] = '\0';
	i = 0;
	while (prec-- != 0)
	{
		str[i++] = base_str[(int)(value * len_base)];
		value *= len_base;
		value = value - (long int)value;
	}
	if (is_up)
		str = ft_strtoupper(str);
	return (str);
}

char		*ft_ftoa(long double n, short prec)
{
	char		*str;

	prec = (prec < 0) ? 6 : prec;
	if (prec <= 18)
		n += 0.5 / ft_pow(10, prec);
	str = ft_litoa(n);
	if (!prec)
		return (str);
	str = ft_strjoinf(str, ".", 1);
	n = (n - (long int)n) * (n < 0 ? -1 : 1);
	str = ft_strjoinf(str, ft_litoa_under0(n, prec, 10, false), 3);
	return (str);
}

char		*ft_ftoa_base(long double n, short prec, short base, bool is_up)
{
	char		*str;

	if (base < 2 || base > 36)
		return (NULL);
	if (base == 10 || !n)
		return (ft_ftoa(n, prec));
	prec = (prec < 0) ? 6 : prec;
	if (prec <= 18)
		n += 0.05 / ft_pow(10, prec);
	str = ft_litoa_base(n, base, is_up);
	if (!prec)
		return (str);
	str = ft_strjoinf(str, ".", 1);
	n = (n - (long int)n) * (n < 0 ? -1 : 1);
	str = ft_strjoinf(str, ft_litoa_under0(n, prec, base, is_up), 3);
	return (str);
}
