/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:23:52 by wescande          #+#    #+#             */
/*   Updated: 2016/11/18 20:47:02 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_ret;
	size_t	len;

	len = ft_strlen(s);
	if (!(s_ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s_ret = ft_memcpy(s_ret, s, len + 1);
	return (s_ret);
}
