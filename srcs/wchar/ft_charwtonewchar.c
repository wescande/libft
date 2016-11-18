/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charwtonewchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:27:23 by wescande          #+#    #+#             */
/*   Updated: 2016/11/18 13:28:29 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charwtonewchar(const wchar_t cw)
{
	char	*c;

	if (!(c = (char*)malloc(sizeof(char) * (ft_charwlen(cw)))))
		return (NULL);
	return (ft_charwtochar(c, cw));
}
