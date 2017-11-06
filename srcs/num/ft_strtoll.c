/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:40:48 by wescande          #+#    #+#             */
/*   Updated: 2017/11/06 14:41:29 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int64_t			ft_strtoll(const char *string, char **endptr, uint8_t base)
{
	register const char		*p;
	int64_t					result;

	p = string;
	while (ft_isspa(*p))
		++p;
	if (*p == '-')
	{
		++p;
		result = -(strtoul(p, endptr, base));
	}
	else
	{
		if (*p == '+')
		{
			++p;
		}
		result = strtoul(p, endptr, base);
	}
	if ((result == 0) && (endptr != 0) && (*endptr == p))
		*endptr = (char *)string;
	return (result);
}
