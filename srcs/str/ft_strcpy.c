/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 23:15:22 by wescande          #+#    #+#             */
/*   Updated: 2016/08/31 23:25:13 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*ret;

	ret = dest;
	while (*src)
	{
		*ret = *src;
		++ret;
		++src;
	}
	*ret = '\0';
	return (dest);
}
