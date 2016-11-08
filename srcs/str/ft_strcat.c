/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 23:35:35 by wescande          #+#    #+#             */
/*   Updated: 2016/09/16 01:00:27 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*ret;

	ret = dest;
	while (*ret)
		++ret;
	while (*src)
	{
		*ret = *src;
		++ret;
		++src;
	}
	*ret = '\0';
	return (dest);
}
