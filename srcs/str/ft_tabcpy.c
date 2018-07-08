/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:42:21 by wescande          #+#    #+#             */
/*   Updated: 2017/11/22 11:45:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	**ft_tabcpy(void** dest, void **src)
{
	void **anchor;

	anchor = dest;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = NULL;
	return (anchor);
}