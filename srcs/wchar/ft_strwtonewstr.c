/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwtonewstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:23:22 by wescande          #+#    #+#             */
/*   Updated: 2016/11/18 13:28:59 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strwtonewstr(const wchar_t *strw)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (ft_strwlen(strw)))))
		return (NULL);
	return (ft_strwtostr(str, strw));
}
