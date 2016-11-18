/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:18:24 by wescande          #+#    #+#             */
/*   Updated: 2016/11/18 11:28:22 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_litoa(long int n)
{
	int			len;
	long int	nb_tmp;
	char		*str;

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

char	*ft_litoa_base_maj(long int value, short int len_base)
{
	char *base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *str;
	int len;
	long int nb_tmp;
	short int is_neg;

	if (len_base < 2 || len_base > 36)
		return (NULL);
	if (len_base == 10)
		return (ft_litoa(value));
	if (!value)
		return (ft_strnewc(1, '0'));
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
	return (str);
}

char	*ft_litoa_base_min(long int value, short int len_base)
{
	char *base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *str;
	int len;
	long int nb_tmp;
	short int is_neg;

	if (len_base < 2 || len_base > 36)
		return (NULL);
	if (len_base == 10)
		return (ft_litoa(value));
	if (!value)
		return (ft_strnewc(1, '0'));
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
	return (str);
}
