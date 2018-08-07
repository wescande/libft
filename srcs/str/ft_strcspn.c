/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:14:50 by wescande          #+#    #+#             */
/*   Updated: 2018/08/07 20:19:56 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(char *s, const char *reject)
{
	char	*str;

	str = s;
	while (*str)
	{
		if (ft_strchr(reject, *str))
			return (str - s);
		str++;
	}
	return (str - s);
}
