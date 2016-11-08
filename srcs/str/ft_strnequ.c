/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:41:19 by wescande          #+#    #+#             */
/*   Updated: 2016/11/04 12:05:12 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (--n && *s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	if (*s1 == *s2)
		return (1);
	return (0);
}
