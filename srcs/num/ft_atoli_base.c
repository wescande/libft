/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:53:18 by wescande          #+#    #+#             */
/*   Updated: 2016/12/16 14:50:47 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_atoli_base(const char *nptr, short len)
{
	long int	nb;
	static char	*base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int			is_neg;
	char		*pos;

	nb = 0;
	is_neg = false;
	if (!nptr || len > 26 || len < 2)
		return (0);
	while (ft_isspa(*nptr))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
		is_neg = (*(nptr++) == '-');
	while ((pos = ft_memchr(base, ft_toupper(*nptr), len)))
	{
		nb = nb * len + (pos - base);
		++nptr;
	}
	if (is_neg)
		return (-nb);
	return (nb);
}
