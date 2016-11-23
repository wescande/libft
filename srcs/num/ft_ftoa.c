/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:43:26 by wescande          #+#    #+#             */
/*   Updated: 2016/11/23 19:10:32 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_litoa_under0(long double value, short int prec, bool is_up)
{
	static char	*base_str = "0123456789abcdef";
	char		*str;
	short int	i;

	if (!(str = (char*)malloc(sizeof(char) * (prec + 1))))
		return (NULL);
	str[prec] = '\0';
	i = 0;
	while (prec-- != 0)
	{
		str[i++] = base_str[(int)(value * 16.0)];
		value *= 16.0;
		value = value - (long int)value;
	}
	if (is_up)
		str = ft_strtoupper(str);
	return (str);
}

char	*ft_ftoa(long double n, short prec)
{
	char		*str;
	long int	ten_prec;

	str = ft_litoa(n);
	prec = (prec < 0) ? 6 : prec;
	prec = (prec > 18) ? 18 : prec;
	ten_prec = ft_pow(10, prec);
	if (!prec)
		return (str);
	n += (0.5 / ten_prec);
	str = ft_strjoinf(str, ".", 1);
	n = ft_abs((n - (long int)n) * ten_prec);
	str = ft_strjoinf(str, ft_litoa(n), 3);
	return (str);
}

char	*ft_ftoa_base(long double n, short prec, short base, bool is_up)
{
	char		*str;
	long int	ten_prec;

	if (base < 2 || base > 36)
		return (NULL);
	if (base == 10 || !n)
		return (ft_ftoa(n, prec));
	str = ft_litoa_base(n, base, is_up);
	prec = (prec < 0) ? 6 : prec;
	prec = (prec > 18) ? 18 : prec;
	ten_prec = ft_pow(10, prec);
	if (!prec)
		return (str);
	n += (0.0005 / ten_prec);
	str = ft_strjoinf(str, ".", 1);
	n = (n - (long int)n) * (n < 0 ? -1 : 1);
	str = ft_strjoinf(str, ft_litoa_under0(n, prec, is_up), 3);
	return (str);
}
