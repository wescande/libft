/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:53:18 by wescande          #+#    #+#             */
/*   Updated: 2017/11/06 15:09:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t		ft_atolli_base(const char *nptr, uint8_t base)
{
	return (ft_strtoll(nptr, (char**)NULL, base));
}
