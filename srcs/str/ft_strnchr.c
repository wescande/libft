/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 00:27:16 by wescande          #+#    #+#             */
/*   Updated: 2017/09/05 18:36:08 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, size_t len)
{
	char	cch;

	cch = (char)c;
	if (!s || !len)
		return (NULL);
	while (len-- && *s != cch)
		++s;
	if (*s == cch)
		return ((char*)s);
	return (NULL);
}
