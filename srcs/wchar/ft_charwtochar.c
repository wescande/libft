/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charwtochar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:53:17 by wescande          #+#    #+#             */
/*   Updated: 2016/11/21 16:23:57 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charwtochar(char *str, const wchar_t cw)
{
	char *s;

	s = str;
	if (cw <= 0x7F)
		*s = cw;
	else if (cw <= 0x7FF)
	{
		*s = (cw >> 6) + 0xC0;
		*(++s) = (cw & 0x3F) + 0x80;
	}
	else if (cw <= 0xFFFF)
	{
		*s = (cw >> 12) + 0xE0;
		*(++s) = ((cw >> 6) & 0x3F) + 0x80;
		*(++s) = (cw & 0x3F) + 0x80;
	}
	else if (cw <= 0x10FFFF)
	{
		*s = (cw >> 18) + 0xF0;
		*(++s) = ((cw >> 12) & 0x3F) + 0x80;
		*(++s) = ((cw >> 6) & 0x3F) + 0x80;
		*(++s) = (cw & 0x3F) + 0x80;
	}
	*(++s) = '\0';
	return (str);
}
