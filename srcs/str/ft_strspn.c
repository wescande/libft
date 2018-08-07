/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:16:58 by wescande          #+#    #+#             */
/*   Updated: 2018/08/07 20:19:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(char *s, const char *accept)
{
	char	*str;

	str = s;
	while (*str)
	{
		if (!ft_strchr(accept, *str))
			return (str - s);
		str++;
	}
	return (str - s);
}
