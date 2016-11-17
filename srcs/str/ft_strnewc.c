/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:37:32 by wescande          #+#    #+#             */
/*   Updated: 2016/11/17 15:37:38 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewc(size_t size, int c)
{
	char *sptr;

	if (!(sptr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset((void*)sptr, c, size);
	sptr[size] = '\0';
	return (sptr);
}
