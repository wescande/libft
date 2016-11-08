/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:23:52 by wescande          #+#    #+#             */
/*   Updated: 2016/08/31 23:19:11 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_ret;

	if (!(s_ret = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	s_ret = ft_strcpy(s_ret, s);
	return (s_ret);
}
