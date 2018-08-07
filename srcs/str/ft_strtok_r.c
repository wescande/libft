/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:03:04 by wescande          #+#    #+#             */
/*   Updated: 2018/08/07 20:19:06 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strtok_r (char *str, const char *delim, char **save_ptr)
{
	char *end;

	if (str == NULL)
		str = *save_ptr;
	if (*str == '\0')
	{
		*save_ptr = str;
		return NULL;
	}
	str += ft_strspn(str, delim);
	if (*str == '\0')
	{
		*save_ptr = str;
		return NULL;
	}
	end = str + ft_strcspn(str, delim);
	if (*end == '\0')
	{
		*save_ptr = end;
		return str;
	}
	*end = '\0';
	*save_ptr = end + 1;
	return str;
}
