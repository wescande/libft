/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:38:42 by wescande          #+#    #+#             */
/*   Updated: 2016/11/02 17:48:48 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *sptr;

	if (!(sptr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero((void*)sptr, size + 1);
	return (sptr);
}
