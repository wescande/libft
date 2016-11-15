/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:18:24 by wescande          #+#    #+#             */
/*   Updated: 2016/11/14 18:18:31 by wescande         ###   ########.fr       */
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
