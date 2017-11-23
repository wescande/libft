/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsepjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:19:42 by wescande          #+#    #+#             */
/*   Updated: 2017/11/23 18:37:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsepjoin_crlf(char **tab, char sep)
{
	char	*join;
	char	**p;
	int		len;

	len = 0;
	if (!(p = tab))
		return (NULL);
	while (*p)
		len += ft_strlen(*p++) + 1;
	if (!(join = (char *)malloc(len + 2)))
		return (NULL);
	*join = 0;
	p = tab;
	while (*p)
	{
		ft_strcat(join, *p++);
		if (*p)
			ft_strcat(join, &sep);
	}
	ft_strcat(join, "\r\n");
	return (join);
}

char	*ft_strsepjoin(char **tab, char sep)
{
	char	*join;
	char	**p;
	int		len;

	len = 0;
	if (!(p = tab))
		return (NULL);
	while (*p)
		len += ft_strlen(*p++) + 1;
	if (!(join = (char *)malloc(len)))
		return (NULL);
	*join = 0;
	p = tab;
	while (*p)
	{
		ft_strcat(join, *p++);
		if (*p)
			ft_strcat(join, &sep);
	}
	join[len - 1] = 0;
	return (join);
}
