/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charwlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:39:21 by wescande          #+#    #+#             */
/*   Updated: 2016/11/17 13:14:37 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short int	ft_charwlen(const wchar_t cw)
{
	if (cw <= 0x7F)
		return (1);
	else if (cw <= 0x7FF)
		return (2);
	else if (cw <= 0xFFFF)
		return (3);
	else if (cw <= 0x10FFFF)
		return (4);
	return (0);
}
