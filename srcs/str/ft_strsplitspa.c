/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitspa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:30:08 by wescande          #+#    #+#             */
/*   Updated: 2016/12/06 14:33:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcpy_c(char *dest, char const *src)
{
	int decalage;

	decalage = 0;
	while (*src && !ft_isspa(*src))
	{
		*dest = *src;
		++dest;
		++src;
		++decalage;
	}
	*dest = '\0';
	return (decalage);
}

static int		ft_strlen_c(char const *str)
{
	int len;

	len = 0;
	while (*str && !ft_isspa(*str))
	{
		++str;
		++len;
	}
	return (len);
}

static int		ft_nbstr_c(char const *str)
{
	int len;

	len = 0;
	while (*str)
	{
		while (*str && ft_isspa(*str))
			++str;
		if (*str)
			++len;
		while (*str && !ft_isspa(*str))
			++str;
	}
	return (len);
}

char			**ft_strsplit_spa(char const *str)
{
	char	**s1;
	int		i;

	if (!str)
		return (NULL);
	if (!(s1 = (char**)malloc(sizeof(*s1) * (ft_nbstr_c(str) + 1))))
		return (NULL);
	i = 0;
	while (*str && ft_isspa(*str))
		++str;
	while (*str)
	{
		if (!(s1[i] = (char*)malloc(sizeof(**s1) * (ft_strlen_c(str) + 1))))
			return (NULL);
		str = str + ft_strcpy_c(s1[i], str);
		++i;
		while (*str && ft_isspa(*str))
			++str;
	}
	s1[i] = 0;
	return (s1);
}
