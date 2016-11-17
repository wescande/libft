/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:12:42 by wescande          #+#    #+#             */
/*   Updated: 2016/11/17 19:13:06 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short int	ft_num_len_base(long num, short int len_base)
{
	short int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= len_base;
		++len;
	}
	return (len);
}
