/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:45:59 by wescande          #+#    #+#             */
/*   Updated: 2016/11/17 12:43:32 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strwlen(const wchar_t *strw)
{
	size_t	wlen;

	wlen = 0;
	while (*strw)
		wlen += ft_charwlen(*(strw++));
	return (wlen);
}
