/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:18:24 by wescande          #+#    #+#             */
/*   Updated: 2016/12/16 14:51:21 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_litoa(long int n)
{
	int			len;
	long int	nb_tmp;
	char		*str;

	if (!n)
		return (ft_strdup("0"));
	len = ((n <= 0) ? 1 : 0);
	nb_tmp = n;
	while (++len && nb_tmp)
		nb_tmp /= 10;
	if (!(str = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	nb_tmp = n;
	while (nb_tmp != 0)
	{
		str[--len] = '0' + ((n < 0) ? -1 : 1) * (nb_tmp % 10);
		nb_tmp /= 10;
	}
	if (n < 0)
		*str = '-';
	return (str);
}

char	*ft_ulitoa(unsigned long int n)
{
	int					len;
	unsigned long int	nb_tmp;
	char				*str;

	if (!n)
		return (ft_strdup("0"));
	len = 0;
	nb_tmp = n;
	while (++len && nb_tmp)
		nb_tmp /= 10;
	if (!(str = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	nb_tmp = n;
	while (nb_tmp != 0)
	{
		str[--len] = '0' + (nb_tmp % 10);
		nb_tmp /= 10;
	}
	return (str);
}

char	*ft_litoa_base(long int value, short int len_base, int is_up)
{
	static char	*base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	char		*str;
	int			len;
	long int	nb_tmp;
	short int	is_neg;

	if (len_base < 2 || len_base > 36)
		return (NULL);
	if (len_base == 10 || !value)
		return (ft_litoa(value));
	is_neg = (value < 0) ? -1 : 1;
	len = ft_num_len_base(value, len_base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	nb_tmp = value;
	while (nb_tmp != 0)
	{
		str[--len] = base_str[is_neg * (nb_tmp % len_base)];
		nb_tmp /= len_base;
	}
	if (is_up)
		str = ft_strtoupper(str);
	return (str);
}

char	*ft_ulitoa_base(unsigned long int value, short int len_base, int is_up)
{
	static char			*base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	char				*str;
	int					len;
	unsigned long int	nb_tmp;

	if (len_base < 2 || len_base > 36)
		return (NULL);
	if (len_base == 10 || !value)
		return (ft_ulitoa(value));
	len = ft_unum_len_base(value, len_base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	nb_tmp = value;
	while (nb_tmp != 0)
	{
		str[--len] = base_str[nb_tmp % len_base];
		nb_tmp /= len_base;
	}
	if (is_up)
		str = ft_strtoupper(str);
	return (str);
}
